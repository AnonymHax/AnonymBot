#include "Translator.h"

QHash<QString, ConversionVariable> Translator::m_variables;
bool Translator::m_isInit = false;

Translator::Translator()
{
    init();
}

FunctionData Translator::translateFunction(FunctionData function, QList<ClassVariable> classVariables, ClassInfos classInfos)
{
    init();

    int brackets = 0;
    QString content;

    QTextStream in(&function.content, QIODevice::ReadOnly);
    QTextStream out(&content, QIODevice::WriteOnly);

    QString line;

    QMultiHash<QString, QString> variables;

    foreach(const ConversionVariable &conv, m_variables)
    {
        if(conv.link == SINGLETON || conv.link == STATIC || conv.link == ENUM)
            variables.insert(conv.originalType, conv.originalType);
    }

    foreach(ClassVariable classVariable, classVariables)
    {
        if(classVariable.variable.isContainer)
            variables.insert(classVariable.variable.name, classVariable.variable.containerShell.type);

        variables.insert(classVariable.variable.name, classVariable.variable.type);
    }

    foreach(Variable variable, function.prototype.parameters)
    {
        if(variable.isContainer)
            variables.insert(variable.name, variable.type);

        variables.insert(variable.name, variable.type);
    }


    do
    {
        line = in.readLine();
        line = line.simplified();

        QStringList list = line.split(' ');

        //Brackets
        if(list.contains("}"))
            brackets --;

        if(list.contains("{"))
            brackets ++;

        if(line.contains(" as "))
            line = Translator::translateConversion(line);

        QStringList variableNames(variables.keys());
        variableNames.removeDuplicates();

        foreach(QString varName, variableNames)
            line = processMethod(line, varName, variables);

        if(line.contains(" = ClassManagerSingleton::get()->getClass"))
        {
            QString varName = line.mid(0, line.indexOf(" = ClassManagerSingleton::get()->getClass")).simplified();
            varName.remove("this.");

            QString varType = variables.values(varName)[0];
            QString cast;
            cast = m_variables[varType].translatedType;

            if(m_variables[varType].link == POINTER)
                cast += "*";

            line.insert(line.indexOf("ClassManagerSingleton::get()"), "qSharedPointerCast<"+cast+">(");
            line.insert(line.indexOf(";"), ")");
        }

        line = fixLink(line);
        line = fixMissingTypeBug(line, variables);

        if(line.contains("var "))
        {
            line = line.remove("var");
            line.replace("NaN;", "NULL;");
            QStringList list = line.split(" ", QString::SkipEmptyParts);
            QString name = list[0].split(":")[0];
            QString type = list[0].split(":")[1];

            Variable variable;
            variable.type = type;

            variable = translateVariable(variable);

            line.clear();

            if(variable.link == SHARED_POINTER)
                line += "QSharedPointer<";

            line += variable.type;

            if(variable.link == POINTER)
                line += "*";

            else if(variable.link == SHARED_POINTER)
                line += ">";

            line += " ";

            line +=name;

            if(!list.filter("null").isEmpty() && variable.link != POINTER)
            {
                list.replace(list.indexOf(list.filter("null").first()), list.filter("null").first().remove("null"));
                list.removeOne("=");
            }

            else if(!list.filter("null").isEmpty())
                list.replace(list.indexOf(list.filter("null").first()), list.filter("null").first().replace("null", "NULL"));

            for(int i = 1; i < list.size(); i++)
                line += " "+list[i];

            variables.insert(name, type);
        }

        if(line.contains("throw new Error"))
        {
            line.remove(15, 1);
            line.remove(line.size()-2, 1);
            line.replace("throw new Error", "qDebug()<<\"ERREUR - "+classInfos.name+" -\"<<");
            line.replace("+", "<<");
        }

        if(line.contains("super."))
        {
            QString parentClass;

            foreach(const InheritedClass &inherited, classInfos.inheritedClasses)
            {
                if(Translator::isTranslated(inherited.name))
                {
                    parentClass = inherited.name;
                    break;
                }
            }

            line.replace("super.", parentClass+"::");
        }

        if(line.contains("] = ")) // Fix rapide du probleme d'acces a un tableau vide (allocation dynamique en AS3)
        {
            QString toReplace = " = ";

            for(int i = line.indexOf("] = "); i != -1; i--)
            {
                toReplace.insert(0, line[i]);

                if(line[i] == '[')
                    break;
            }

            line.replace(toReplace, "<<");
        }

        if(line.contains("this."))
            line.replace("this.", "this->");

        out<<line;

        if(in.pos()+1 < function.content.size())
            out<<"\n";

    } while(!line.isNull());

    function.content = content;

    for(int i = 0; i < function.prototype.parameters.size(); i++)
        function.prototype.parameters[i] = translateVariable(function.prototype.parameters[i]);

    return function;
}

Variable Translator::translateVariable(Variable variable)
{
    init();

    if(variable.isContainer)
    {
        Variable secondVariable;
        secondVariable.type = variable.containerShell.type;
        secondVariable.link = variable.containerShell.link;
        secondVariable = translateVariable(secondVariable);
        variable.containerShell.type = secondVariable.type;
        variable.containerShell.link = secondVariable.link;
    }

    if(m_variables.contains(variable.type))
    {
        variable.link = m_variables[variable.type].link ;
        variable.type = m_variables[variable.type].translatedType;
    }

    else if(!m_variables.contains(variable.type))
        qDebug()<<"ERREUR - Translator - Le type"<<variable.type<<"n'est pas connu de la base de donnée";

    return variable;
}

ClassVariable Translator::translateClassVariable(ClassVariable variable)
{
    init();

    variable.variable = translateVariable(variable.variable);

    return variable;
}

QString Translator::translateInclude(QString include)
{
    if(include.contains("com.ankamagames.dofus.network.types."))
    {
        include = QString(CLASS_PATH)+"/"+include.remove("com.ankamagames.dofus.network.types.");
        include.replace(".", "/");
        include += ".h";
    }

    else if(include.contains("com.ankamagames.dofus.network.enums."))
    {
        include = QString(ENUM_PATH)+"/"+include.remove("com.ankamagames.dofus.network.enums.");
        include.replace(".", "/");
        include += ".h";
    }

    else if(include.contains("com.ankamagames.dofus.datacenter."))
    {
        include = QString(DATA_PATH)+"/"+include.remove("com.ankamagames.dofus.datacenter.");
        include.replace(".", "/");
        include += "Data.h";
    }

    else if(include.contains("ProtocolTypeManager"))
        include = QString(CLASS_UTILS_PATH)+"/ClassManager.h";

    else if(include.contains("BooleanByteWrapper"))
        include = BOOLEANBYTEWRAPPER_PATH;

    else
        return QString();

    return include;
}

QString Translator::translateConversion(QString line)
{
    if(line.contains(" as "))
    {
        int index = line.indexOf(" as ");
        int indexBeg = index;
        int indexEnd = index;

        int brackets = 1;
        for(int i = index; i >= 0; i--)
        {
            if(line[i] == ')')
                brackets++;

            if(line[i] == '(')
                brackets--;

            if(brackets == 0 && line[i] == '(')
            {
                indexBeg = i;
                break;
            }
        }

        brackets = 1;
        for(int i = index; i < line.size(); i++)
        {
            if(line[i] == ')')
                brackets--;

            if(line[i] == '(')
                brackets++;

            if(brackets == 0 && line[i] == ')')
            {
                indexEnd = i+1;
                break;
            }
        }

        QString convertClass = line.mid(index+4, indexEnd-index-5);

        QString originalInstruction = line.mid(indexBeg, indexEnd);
        originalInstruction.remove(line.mid(indexEnd));
        QString translatedInstruction = originalInstruction;
        translatedInstruction.remove(line.mid(index, indexEnd-index-1));

        QString add;

        if(m_variables.contains(convertClass))
        {
            if(m_variables[convertClass].link == SHARED_POINTER)
                add = "qSharedPointerCast<"+m_variables[convertClass].translatedType;

            if(m_variables[convertClass].link == POINTER)
                add += "*";

            if(m_variables[convertClass].link == SHARED_POINTER)
                add += ">";

            translatedInstruction = add + translatedInstruction;

            QMultiHash<QString, QString> variables;
            variables.insert(translatedInstruction, convertClass);

            return translateConversion(processMethod(line.replace(originalInstruction, translatedInstruction), translatedInstruction, variables));
        }

        else
            qDebug()<<"ERREUR - Translator - Ne connait pas la classe"<<convertClass;
    }

    return line;
}

bool Translator::isKnown(const QString &className)
{
    if(m_variables.contains(className))
        return true;

    return false;
}

void Translator::init()
{
    if(!m_isInit)
    {
        m_isInit = true;

        addConversionVariable("Vector", "QList");
        addConversionVariable("ByteArray", "QByteArray");
        addConversionVariable("String", "QString");
        addConversionVariable("Boolean", "bool");
        addConversionVariable("double", "double");
        addConversionVariable("short", "short");
        addConversionVariable("int", "int");
        addConversionVariable("uint", "uint");
        addConversionVariable("Number", "double");
        addConversionVariable("*", "auto");

        addConversionVariable("ICustomDataInput", "Reader", POINTER);
        addConversionVariable("ICustomDataOutput", "Writer", POINTER);
        addConversionVariable("IDataCenter", "");
        addConversionVariable("Object", "");
        addConversionVariable("INetworkType", "");
        addConversionVariable("NetworkMessage", "");
        addConversionVariable("INetworkDataContainerMessage", "");
        addConversionVariable("INetworkMessage", "");

        addConversionVariable("ProtocolTypeManager", "ClassManagerSingleton", SINGLETON);
        addConversionVariable("BooleanByteWrapper", "BooleanByteWrapper", STATIC);

        ConversionFunction funct;

        funct.isSelfActionNotDetainedByClass = false;

        funct.originalName = "getInstance";
        funct.translatedName = "getClass";
        funct.parameters<<"#1#";
        addFunction("ProtocolTypeManager", funct);

        funct.originalName = "setFlag";
        funct.translatedName = "setFlag";
        funct.parameters.clear();
        funct.parameters<<"#0#"<<"#1#"<<"#2#";
        addFunction("BooleanByteWrapper", funct);

        funct.originalName = "getFlag";
        funct.translatedName = "getFlag";
        funct.parameters.clear();
        funct.parameters<<"#0#"<<"#1#";
        addFunction("BooleanByteWrapper", funct);

        funct.parameters.clear();

        // READER

        funct.originalName = "readBoolean";
        funct.translatedName = "readBool";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readByte";
        funct.translatedName = "readByte";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readUnsignedByte";
        funct.translatedName = "readUByte";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readInt";
        funct.translatedName = "readInt";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readUnsignedInt";
        funct.translatedName = "readUInt";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readShort";
        funct.translatedName = "readShort";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readUnsignedShort";
        funct.translatedName = "readUShort";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readDouble";
        funct.translatedName = "readDouble";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readFloat";
        funct.translatedName = "readFloat";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readUTF";
        funct.translatedName = "readUTF";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readUTFBytes";
        funct.translatedName = "readUTFBytes";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarInt";
        funct.translatedName = "readVarInt";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarUhInt";
        funct.translatedName = "readVarUhInt";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarShort";
        funct.translatedName = "readVarShort";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarUhShort";
        funct.translatedName = "readVarUhShort";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarLong";
        funct.translatedName = "readVarLong";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readVarUhLong";
        funct.translatedName = "readVarUhLong";
        addFunction("ICustomDataInput", funct);

        funct.originalName = "readBytes";
        funct.translatedName = "readBytes";
        funct.receiver = "#0#";
        addFunction("ICustomDataInput", funct);


        // WRITER

        funct.receiver.clear();
        funct.parameters<<"#0#";

        funct.originalName = "writeBoolean";
        funct.translatedName = "writeBool";
        funct.parameters.clear();
        funct.parameters<<"#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeByte";
        funct.translatedName = "writeByte";
        funct.parameters.clear();
        funct.parameters<<"#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeInt";
        funct.translatedName = "writeInt";
        funct.parameters.clear();
        funct.parameters<<"(int)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeUnsignedInt";
        funct.translatedName = "writeUInt";
        funct.parameters.clear();
        funct.parameters<<"(uint)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeShort";
        funct.translatedName = "writeShort";
        funct.parameters.clear();
        funct.parameters<<"(short)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeUnsignedShort";
        funct.translatedName = "writeUShort";
        funct.parameters.clear();
        funct.parameters<<"(ushort)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeDouble";
        funct.translatedName = "writeDouble";
        funct.parameters.clear();
        funct.parameters<<"#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeFloat";
        funct.translatedName = "writeFloat";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeUTF";
        funct.translatedName = "writeUTF";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeUTFBytes";
        funct.translatedName = "writeUTFBytes";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeBytes";
        funct.translatedName = "writeBytes";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeVarInt";
        funct.translatedName = "writeVarInt";
        funct.parameters.clear();
        funct.parameters<<"(int)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeVarShort";
        funct.translatedName = "writeVarShort";
        funct.parameters.clear();
        funct.parameters<<"(int)#0#";
        addFunction("ICustomDataOutput", funct);

        funct.originalName = "writeVarLong";
        funct.translatedName = "writeVarLong";
        funct.parameters.clear();
        funct.parameters<<"(double)#0#";
        addFunction("ICustomDataOutput", funct);

        // OTHERS

        funct.originalName = "uncompress";
        funct.translatedName = "gUncompress";
        funct.isSelfActionNotDetainedByClass = true;
        funct.parameters.clear();
        funct.parameters<<"#self#";
        addFunction("ByteArray", funct);

        funct.originalName = "length";
        funct.translatedName = "size";
        funct.isSelfActionNotDetainedByClass = false;
        funct.parameters.clear();
        addFunction("ByteArray", funct);

        funct.originalName = "length";
        funct.translatedName = "size";
        addFunction("Vector", funct);

        funct.originalName = "size";
        funct.translatedName = "size";
        addFunction("Vector", funct);

        funct.originalName = "push";
        funct.translatedName  = "append";
        funct.parameters<<"#0#";
        addFunction("Vector", funct);
    }
}

QString Translator::processMethod(QString line, QString varName, QMultiHash<QString, QString> variables)
{
    init();

    if(line.contains(varName+".") || (line.contains(varName+"[") && line.contains("].")))
    {
        int check = line.indexOf(varName+".")-1;

        if(check >= 0 && (line[check].isLetter() || line[check].isNumber()))
            return line;


        bool useContainer = false;
        QString containerParameter;

        if(line.contains(varName+"[") && line.contains("]."))
        {
            useContainer = true;
            int index = line.indexOf("[")+1;

            for(int i = index; i < line.size(); i++)
            {
                if(line[i] == ']')
                    break;

                containerParameter += line[i];
            }
        }

        int indexBeg = 0;
        int indexFunct = 0;
        int indexEnd = 0;
        QString functName;
        QStringList parameters;

        if(!useContainer)
        {
            indexBeg = line.indexOf(varName+".");
            indexFunct = indexBeg+varName.size()+1;
        }

        else
        {
            indexBeg = line.indexOf(varName+"[");
            indexFunct = indexBeg+varName.size()+1+containerParameter.size()+2;
        }

        int brackets = 0;
        bool isString = false;
        bool oneWord = true;
        QString parameter;

        indexEnd = indexBeg;

        for(int i = indexFunct; i < line.size(); i++)
        {
            if(oneWord &&
                    (line[i] == ' ' ||
                     line[i] == '<' ||
                     line[i] == '>' ||
                     line[i] == '*' ||
                     line[i] == '(' ||
                     line[i] == ')' ||
                     line[i] == ';' &&
                     brackets == 0))
            {
                oneWord = false;
                indexEnd = i;
            }

            if(brackets == 0 && oneWord)
                functName += line[i];

            if(line[i] == '\"')
            {
                if(isString)
                    isString = false;

                else
                    isString = true;
            }

            if(line[i] == '(')
                brackets++;

            else if(line[i] == ')')
            {
                if(brackets == 1)
                {
                    parameters<<parameter;
                    indexEnd = i+1;
                }

                brackets--;
            }


            if(line[i] != ' ' && (line[i] != ',' || isString || brackets > 1) && brackets >= 1)
            {
                if(line[i] != '(' || brackets != 1)
                    parameter += line[i];
            }

            else if(line[i] == ',' && !isString && brackets == 1)
            {
                parameters<<parameter;
                parameter.clear();
            }
        }

        //        qDebug()<<"CONTAINER PARAM"<<containerParameter;

        //        foreach(QString x, parameters)
        //            qDebug()<<"PARAM"<<x;

        //        qDebug()<<"FUNCT NAME"<<functName;

        //        qDebug()<<"CONCERNED"<<line.mid(indexBeg, indexEnd-indexBeg);

        QString translated = line.mid(indexBeg, indexEnd-indexBeg);

        if(m_variables[variables.values(varName)[useContainer]].functions.contains(functName) && !translated.contains(".\""))
            translated = translateMethod(varName, containerParameter, functName, parameters, variables);

        else if(!translated.contains(".\""))
            qDebug()<<"ERREUR - Translator - Ne connait pas la fonction"<<functName
                   <<"appartenant au type"<<variables.values(varName)[useContainer]
                     <<"nommé ici"<<varName
                    <<"ligne"<<line;

        line = processMethod(line.mid(0, indexBeg), varName, variables)+translated+processMethod(line.mid(indexEnd), varName, variables);
    }

    return line;
}

QString Translator::translateMethod(QString varName, QString contained, QString functName, QList<QString> parameters, QMultiHash<QString, QString> variables)
{
    init();

    QString translated;
    bool isContainer = !contained.isEmpty();

    if(!m_variables[variables.values(varName)[isContainer]].functions[functName].receiver.isEmpty())
    {
        if(m_variables[variables.values(varName)[isContainer]].functions[functName].receiver.contains("#"))
        {
            int paramNumber = QString(m_variables[variables.values(varName)[isContainer]].functions[functName].receiver.at(m_variables[variables.values(varName)[isContainer]].functions[functName].receiver.indexOf("#")+1)).toInt();
            translated += parameters[paramNumber];
        }

        else if(m_variables[variables.values(varName)[isContainer]].functions[functName].receiver == "#self#")
        {
            if(m_variables[variables.values(varName)[isContainer]].link == POINTER)
                translated += "*";

            translated += varName;
        }

        else if(m_variables[variables.values(varName)[isContainer]].functions[functName].receiver == "#selfPointer#")
        {
            if(!m_variables[variables.values(varName)[isContainer]].link == POINTER)
                translated += "&";

            translated += varName;
        }

        else
            translated += m_variables[variables.values(varName)[isContainer]].functions[functName].receiver;

        translated += " = ";
    }

    if(m_variables[variables.values(varName)[isContainer]].link == ENUM)
        translated += "(int)";

    if(m_variables[variables.values(varName)[isContainer]].link == SINGLETON)
        translated += m_variables[variables.values(varName)[isContainer]].translatedType+"::get()";

    else
        translated += varName;

    if(isContainer)
    {
        QString containedTranslated = contained;

        if(contained.contains(varName+".") ||
                (contained.contains(varName+"[") &&
                 contained.contains("].")))
        {
            containedTranslated = processMethod(contained, varName, variables);
        }


        translated += '['+containedTranslated+']';
    }

    if(!m_variables[variables.values(varName)[isContainer]].functions[functName].isSelfActionNotDetainedByClass)
    {
        if(m_variables[variables.values(varName)[isContainer]].link == POINTER ||
                m_variables[variables.values(varName)[isContainer]].link == SINGLETON ||
                m_variables[variables.values(varName)[isContainer]].link == SHARED_POINTER)
            translated += "->";

        else if(m_variables[variables.values(varName)[isContainer]].link == STATIC || m_variables[variables.values(varName)[isContainer]].link == ENUM)
            translated += "::";

        else
            translated += ".";
    }

    else
        translated += " = ";

    translated += m_variables[variables.values(varName)[isContainer]].functions[functName].translatedName;

    if(m_variables[variables.values(varName)[isContainer]].link != ENUM)
    {
        translated += "(";

        if(!m_variables[variables.values(varName)[isContainer]].functions[functName].parameters.isEmpty())
        {
            for(int i = 0; i < parameters.size(); i++)
                parameters[i] = processMethod(parameters[i], varName, variables);

            for(int i = 0; i <  m_variables[variables.values(varName)[isContainer]].functions[functName].parameters.size(); i++)
            {
                QString parameter = m_variables[variables.values(varName)[isContainer]].functions[functName].parameters[i];

                if(parameter == "#self#")
                {
                    parameter.clear();

                    if(m_variables[variables.values(varName)[isContainer]].link == POINTER)
                        parameter += "*";

                    parameter += varName;
                }

                else if(parameter == "#selfPointer#")
                {
                    parameter.clear();

                    if(!m_variables[variables.values(varName)[isContainer]].link == POINTER)
                        parameter += "&";

                    parameter += varName;
                }

                else if(parameter.contains("#"))
                {
                    QString paramNumberString;

                    for(int i = parameter.indexOf("#")+1; i < parameter.size(); i++)
                    {
                        if(parameter[i] == '#')
                            break;

                        paramNumberString += parameter[i];
                    }

                    int paramNumber = paramNumberString.toInt();
                    parameter.replace("#"+paramNumberString+"#", parameters[paramNumber]);
                }


                translated += parameter;

                if(i+1 < m_variables[variables.values(varName)[isContainer]].functions[functName].parameters.size())
                    translated += ", ";
            }
        }

        translated += ")";
    }

    return translated;
}

QString Translator::fixLink(QString line)
{
    if(line.contains("= new "))
    {
        int indexBeg = line.indexOf("= new ")+2;
        int indexEnd = indexBeg+4;
        bool nameStarted = false;

        QString typeName;

        for(int i = indexBeg+4; i < line.size(); i++)
        {
            if(line[i].isLetterOrNumber() || line[i] == '_')
            {
                nameStarted = true;
                typeName += line[i];

                indexEnd++;
            }

            else
            {
                if(nameStarted)
                    break;
            }
        }

        if(m_variables.contains(typeName))
        {
            if(m_variables[typeName].link == POINTER)
                line.replace(line.mid(indexBeg, indexEnd-indexBeg), "new "+m_variables[typeName].translatedType);

            else if(m_variables[typeName ].link == SHARED_POINTER)
                line.replace(line.mid(indexBeg, indexEnd-indexBeg+2), "QSharedPointer<"+m_variables[typeName].translatedType+">(new "+m_variables[typeName].translatedType+"() )");

            else
                line.replace(line.mid(indexBeg, indexEnd-indexBeg), m_variables[typeName].translatedType);
        }

        else
            qDebug()<<"ERREUR - Translator - Ne connait pas le type"<<typeName;
    }

    return line;
}

QString Translator::fixMissingTypeBug(QString line, QMultiHash<QString, QString> &variables)
{
    if(!line.contains("var ") && line.contains(" = "))
    {
        bool nameStarted = false;

        QString varName;

        for(int i = 0; i < line.size(); i++)
        {
            if(line[i].isLetterOrNumber() || line[i] == '.' || line[i] == '_')
            {
                nameStarted = true;
                varName += line[i];
            }

            else
            {
                if(nameStarted)
                    break;
            }
        }

        bool exists = false;

        foreach(const QString &declaredVar, variables.keys())
        {
            if(varName.contains(declaredVar))
            {
                exists = true;
                break;
            }
        }

        if(!exists)
        {
            line.insert(line.indexOf(varName), "auto ");
            variables.insert(varName, "auto");
        }
    }

    return line;
}

void Translator::addTranslated(const QString &className, bool isPointer)
{
    addTranslated(className, className, isPointer);
}

void Translator::addTranslated(const QString &originalName, const QString &translatedName, bool isPointer)
{
    ConversionVariable variable;
    variable.originalType = originalName;
    variable.translatedType = translatedName;

    if(isPointer)
        variable.link = SHARED_POINTER;

    variable.isTranslated = true;

    m_variables[originalName] = variable;
}

void Translator::addFunction(const QString &className, const ConversionFunction &funct)
{
    if(m_variables.contains(className))
        m_variables[className].functions[funct.originalName] = funct;

    else
        qDebug()<<"ERREUR - Translator - Ne connait pas de classe du nom de"<<className<<"a qui l'on puisse rajouter la fonction"<<funct.originalName;
}

bool Translator::isTranslated(const QString &className)
{
    init();

    if(m_variables.contains(className) && m_variables.value(className).isTranslated)
        return true;

    return false;
}

LinkType Translator::getLinkType(const QString &className)
{
    init();

    return m_variables.value(className).link;
}

void Translator::addConversionVariable(const QString &originalType, const QString &translatedType, LinkType type)
{
    ConversionVariable variable;
    variable.originalType = originalType;
    variable.translatedType = translatedType;
    variable.link = type;
    m_variables[originalType] = variable;
}

