#include "DataTranslator.h"

DataTranslator::DataTranslator(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output),
    m_splitter(input),
    m_source(NULL)
{
}

DataTranslator::~DataTranslator()
{
    if(m_source)
        delete m_source;
}

void DataTranslator::parse()
{
    m_splitter.parse();

    foreach(const ClassVariable &var, m_splitter.getClassVariables())
    {
        if(var.variable.name == "MODULE")
        {
            m_module = var.variable.value;
            m_module.remove("\"");
        }

        if(var.inheritance == PUBLIC && !var.variable.isConstant)
        {
            ClassVariable translatedVar = var;

            translatedVar.variable.containerShell.type.remove("Vector.<");
            translatedVar.variable.containerShell.type.remove(">");

            if(Translator::isTranslated(translatedVar.variable.type) && !m_missingIncludes.contains(translatedVar.variable.type))
                m_missingIncludes<<translatedVar.variable.type;

            if(Translator::isTranslated(translatedVar.variable.containerShell.type) && !m_missingIncludes.contains(translatedVar.variable.containerShell.type))
                m_missingIncludes<<translatedVar.variable.containerShell.type;
        }
    }

    ClassInfos classInfos = m_splitter.getClassInfos();

    for(int i = 0; i < classInfos.inheritedClasses.size(); i++)
    {
        if(Translator::isTranslated(classInfos.inheritedClasses[i].name) &&
                !m_missingIncludes.contains(classInfos.inheritedClasses[i].name))
            m_missingIncludes<<classInfos.inheritedClasses[i].name;
    }
}

void DataTranslator::serialize()
{
    ClassInfos classInfos = m_splitter.getClassInfos();
    classInfos.name = getName();

    QList<ClassVariable> classVariables = m_splitter.getClassVariables();

    for(int i = 0; i < classInfos.inheritedClasses.size(); i++)
    {
        if(!Translator::isTranslated(classInfos.inheritedClasses[i].name))
        {
            if(!Translator::isKnown(classInfos.inheritedClasses[i].name))
                qDebug()<<"ERREUR - DataTranslator - Ne connait pas"<<classInfos.inheritedClasses[i].name<<"herité par la classe"<<getName();

            classInfos.inheritedClasses.removeAt(i);
            i--;
        }

        else
        {
            Variable var;
            var.type = classInfos.inheritedClasses[i].name;

            classInfos.inheritedClasses[i].name = Translator::translateVariable(var).type;
        }
    }

    if(classInfos.inheritedClasses.isEmpty())
    {
        InheritedClass baseClass;
        baseClass.name = DATA_BASE_NAME;
        classInfos.inheritedClasses<<baseClass;
    }

    m_source = new SourceSerializer(m_output, classInfos);

    m_source->getHeader().addInclude(QString(DATA_UTILS_PATH)+"/"+QString(DATA_BASE_NAME)+".h");

    foreach(const QString &include, m_manualIncludes)
        m_source->getHeader().addInclude(include);

    for(int i = 0; i < m_anticipatedDeclarations.size(); i++)
    {
        m_source->getHeader().addImplicitClass(m_anticipatedDeclarations[i].first);
        m_source->addInclude(m_anticipatedDeclarations[i].second);
    }

    FunctionData constructor;
    constructor.prototype.name = m_splitter.getClassInfos().name;

    FunctionData loadData;
    loadData.prototype.name = "loadData";
    loadData.prototype.isVirtual = true;
    loadData.prototype.returnType.type = "void";

    Variable fields;
    fields.name = "fields";
    fields.link = REFERENCE;
    fields.type = "QList";
    fields.isContainer = true;
    fields.isConstant = true;
    fields.containerShell.type = "Field";
    fields.containerShell.link = POINTER;

    Variable I18n;
    I18n.name = "I18n";
    I18n.link = POINTER;
    I18n.type = "I18nFile";

    loadData.prototype.parameters<<fields<<I18n;

    QString parentClass;

    foreach(const InheritedClass &inherited, m_splitter.getClassInfos().inheritedClasses)
    {
        if(Translator::isTranslated(inherited.name))
        {
            parentClass = inherited.name;
            break;
        }
    }

    if(!parentClass.isEmpty())
    {
        Variable parentVar;
        parentVar.type = parentClass;
        loadData.content += Translator::translateVariable(parentVar).type+"::loadData(fields, I18n);";
    }

    else
        loadData.content += "m_I18n = I18n;";

    loadData.content += "\n";
    loadData.content += "\nforeach (Field *field, fields)\n{";

    bool isFirst = true;

    foreach(const ClassVariable &var, classVariables)
    {
        if(var.inheritance == PUBLIC && !var.variable.isConstant && !var.variable.name.contains("_") && var.variable.type != "Object")
        {
            ClassVariable translatedVar = var;

            bool isDoubleList = var.variable.containerShell.type.contains("Vector.<");
            translatedVar.variable.containerShell.type.remove("Vector.<");
            translatedVar.variable.containerShell.type.remove(">");

            if(Translator::isKnown(translatedVar.variable.type) && (!translatedVar.variable.isContainer || (Translator::isKnown(translatedVar.variable.containerShell.type))))
            {
                translatedVar = Translator::translateClassVariable(translatedVar);

                translatedVar.variable.name = "m_"+translatedVar.variable.name;

                if(isDoubleList)
                {
                    translatedVar.variable.containerShell.type.insert(0, "QList<");
                    translatedVar.variable.containerShell.type.insert(translatedVar.variable.containerShell.type.size(), ">");
                }

                FunctionData get;
                get.prototype.name = "get"+QString(var.variable.name[0].toUpper())+var.variable.name.mid(1, var.variable.name.size()-1);
                get.prototype.returnType = translatedVar.variable;

                if(translatedVar.variable.isContainer)
                    get.prototype.returnType.type += "<"+translatedVar.variable.containerShell.type+">";

                get.prototype.isConstant = true;
                get.content += "return "+translatedVar.variable.name+";\n";;

                m_source->addFunction(get );
                m_source->getHeader().addClassVariable(translatedVar);

                loadData.content += getFieldTranslatedLine(var.variable, isFirst);

                if(isFirst)
                    isFirst = false;

                loadData.content += "\n";
            }

            else
                qDebug()<<"ERREUR - DataTranslator - A rencontré une variable de type inconnu"<<translatedVar.variable.type<<translatedVar.variable.containerShell.type<<"dans la classe"<<getDofusName();
        }

        else if(var.inheritance == PRIVATE &&
                var.variable.type == "String" &&
                var.variable.name[0] == '_')
        {
            QString complementaryVariableName = var.variable.name;
            complementaryVariableName.remove(0, 1);

            foreach(const ClassVariable &search, classVariables)
            {
                if(search.inheritance == PUBLIC &&
                        !search.variable.isConstant &&
                        search.variable.name.contains(complementaryVariableName) &&
                        search.variable.name.contains("Id"))
                {
                    FunctionData get;
                    get.prototype.name = "get"+QString(search.variable.name[0].toUpper())+search.variable.name.mid(1, search.variable.name.size()-1).remove("Id");
                    get.prototype.returnType.type = "QString";
                    get.prototype.isConstant = true;
                    get.content += "return m_I18n->getText(m_";
                    get.content += search.variable.name+");\n";

                    m_source->addFunction(get);
                    break;
                }
            }

        }
    }

    if(!constructor.content.isEmpty())
        m_source->addFunction(constructor);

    loadData.content += "\n}";
    m_source->addFunction(loadData);

    m_source->serialize();
}

void DataTranslator::write()
{
    m_source->write();
}

void DataTranslator::addManualInclude(QString include)
{
    m_manualIncludes<<include;
}

void DataTranslator::addAnticipatedDeclaration(QString className, QString include)
{
    QPair<QString, QString> pair;
    pair.first = className;
    pair.second = include;
    m_anticipatedDeclarations<<pair;
}

QStringList DataTranslator::getMissingIncludes() const
{
    return m_missingIncludes;
}

QString DataTranslator::getName() const
{
    return m_splitter.getClassInfos().name+"Data";
}

QString DataTranslator::getDofusName() const
{
    return m_splitter.getClassInfos().name;
}

QString DataTranslator::getFieldTranslatedLine(Variable variable, bool isFirst)
{
    QString line;

    if(!isFirst)
        line += "\nelse ";

    else
        line += "\n";

    QString dofusName = variable.name;
    dofusName.remove("m_");

    line += "if(field->getName() == \""+dofusName+"\")";

    if(variable.type == "Vector")
    {
        if(variable.containerShell.type.contains("Vector"))
        {
            variable.containerShell.type.remove("Vector.<");
            variable.containerShell.type.remove(">");

            line += "\n{";
            line += "\nforeach(const QByteArray &firstList, readVector(field->getValue()))";
            line +=  "\n{";
            line += "\nQList<"+Translator::translateVariable(variable).containerShell.type+"> secondList;";
            line += "\n";
            line += "\nforeach (const QByteArray &data, readVector(firstList))";
            line += "\n    secondList << ";

            if(Translator::isTranslated(variable.containerShell.type))
                line += "*qSharedPointerCast<"+Translator::translateVariable(variable).containerShell.type+">(readObject(data, field)).data();";

            else
            {
                line += "read";

                if(variable.containerShell.type == "uint")
                    line += "UInt";

                else if(variable.containerShell.type == "int")
                    line += "Int";

                else if(variable.containerShell.type == "double" || variable.containerShell.type == "Number")
                    line += "Double";

                else if(variable.containerShell.type == "Boolean")
                    line += "Bool";

                else if(variable.containerShell.type == "String")
                    line += "UTF";

                else
                    qDebug()<<"ERREUR - DataTranslator - Ne connait pas le type"<<variable.containerShell.type;

                line += "(data);";
            }

            line += "\n";
            line += "\nm_"+variable.name+" << secondList;";
            line += "\n}";
        }

        else
        {
            line += "\n{";

            line += "\nforeach(const QByteArray &data, readVector(field->getValue()))";

            line += "\n    m_"+variable.name+" << ";

            if(Translator::isTranslated(variable.containerShell.type))
                line += "*qSharedPointerCast<"+Translator::translateVariable(variable).containerShell.type+">(readObject(data, field)).data();";

            else
            {
                line += "read";

                if(variable.containerShell.type == "uint")
                    line += "UInt";

                else if(variable.containerShell.type == "int")
                    line += "Int";

                else if(variable.containerShell.type == "double" || variable.containerShell.type == "Number")
                    line += "Double";

                else if(variable.containerShell.type == "Boolean")
                    line += "Bool";

                else if(variable.containerShell.type == "String")
                    line += "UTF";

                else
                    qDebug()<<"ERREUR - DataTranslator - Ne connait pas le type"<<variable.containerShell.type;

                line += "(data);";
            }
        }

        line += "\n}";
    }

    else if(Translator::isKnown(variable.type))
    {
        line += "\n    m_"+variable.name+" = ";

        if(Translator::isTranslated(variable.type))
            line += "*qSharedPointerCast<"+Translator::translateVariable(variable).type+">(readObject(field->getValue(), field)).data();";

        else
        {
            line += "read";

            if(variable.type == "uint")
                line += "UInt";

            else if(variable.type == "int")
                line += "Int";

            else if(variable.type == "double" || variable.type == "Number")
                line += "Double";

            else if(variable.type == "Boolean")
                line += "Bool";

            else if(variable.type == "String")
                line += "UTF";

            else
                qDebug()<<"ERREUR - DataTranslator - Ne connait pas le type"<<variable.type;

            line += "(field->getValue());";
        }
    }

    else
        qDebug()<<"ERREUR - DataTranslator - Ne connait pas le type"<<variable.type;


    return line;
}

QString DataTranslator::getModule() const
{
    return m_module;
}
