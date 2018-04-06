#include "Splitter.h"

Splitter::Splitter(const QString &input):
    AbstractParser(input)
{
}

void Splitter::parse()
{
    int brackets = 0;
    bool isWaitingForFunction = false;
    int functionBracket = -1;
    bool isWaitingForClass = false;
    int classBracket = -1;

    QFile file(m_input);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"ERREUR - AbstractSerializer - Ouverture du fichier echouée"<<m_input;

    QTextStream in(&file);

    QString line;

    do
    {
        line = in.readLine();
        line = line.simplified();
        QStringList list = line.split(' ');

        //Brackets
        if(list.contains("}"))
        {
            if(functionBracket == brackets)
                functionBracket = -1;

            brackets --;
        }

        if(list.contains("import"))
            readInclude(line.split(' ')[1]);

        if(list.contains("class"))
        {
            isWaitingForClass = true;
            readClass(line);
        }

        if(list.contains("function"))
        {
            readPrototype(line);
            isWaitingForFunction = true;
        }

        if(classBracket == brackets && (list.contains("var") || (list.contains("static") && list.contains("const"))))
            readClassVariable(line);

        if(functionBracket != INVALID && functionBracket <= brackets)
            readContent(line, brackets-functionBracket);

        if(list.contains("{"))
        {
            brackets ++;

            if(isWaitingForClass)
            {
                isWaitingForClass = false;
                classBracket = brackets;
            }

            else if(isWaitingForFunction)
            {
                isWaitingForFunction = false;
                functionBracket = brackets;
            }
        }

    } while(!line.isNull());
}

void Splitter::readInclude(QString line)
{
    m_includes<<line.remove(";");
    qDebug()<<"Include"<<line;
}

void Splitter::readClass(QString line)
{
    m_classInfos.name.clear();
    m_classInfos.inheritedClasses.clear();

    line.remove(",");

    QStringList list = line.split(' ');

    int index = list.indexOf("class");
    m_classInfos.name = list[index+1];

    list.removeAll("extends");
    list.removeAll("implements");

    list = list.mid(index+2, list.size()-index);

    qDebug()<<"ClassName"<<m_classInfos.name;

    foreach(const QString &inheritedName, list)
    {
        qDebug()<<"Inherited by class :"<<inheritedName;

        InheritedClass inherited;
        inherited.name = inheritedName;

        m_classInfos.inheritedClasses<<inherited;
    }
}

void Splitter::readPrototype(QString line)
{
    FunctionData function;

    if(line.contains("public"))
        function.prototype.inheritance = PUBLIC;

    else if(line.contains("private"))
        function.prototype.inheritance = PRIVATE;

    else if(line.contains("protected"))
        function.prototype.inheritance = PROTECTED;

    else
        qDebug()<<"ERREUR - Splitter - Prototype Inheritance";

    if(line.contains("override"))
        function.prototype.isVirtual = true;

    int index;
    QStringList list = line.split(' ');

    if(list.contains("get"))
        index = list.indexOf("get")+1;

    else if(list.contains("set"))
        index = list.indexOf("set")+1;

    else
        index = list.indexOf("function")+1;

    function.prototype.name = list[index].split('(').first();


    QString declaration = list[index].split('(').last();
    index++;
    int tempIndex = 0;
    bool type = false;
    bool defaultValue = false;
    Variable variable;

    while(true)
    {
        if(declaration[tempIndex] == ',' || declaration[tempIndex] == ')')
        {
            if(!variable.name.isEmpty())
                function.prototype.parameters<<variable;

            if(declaration[tempIndex] == ')')
                break;

            type = false;
            defaultValue = false;

            variable.name.clear();
            variable.type.clear();
            variable.value.clear();
        }

        else
        {
            if(declaration[tempIndex] == ':')
                type = true;

            else if(declaration[tempIndex] == '=')
                defaultValue = true;

            else if(defaultValue)
                variable.value += declaration[tempIndex];

            else if(type)
                variable.type += declaration[tempIndex];

            else if(!type)
                variable.name += declaration[tempIndex];

        }

        if(declaration[tempIndex] == ')')
        {
            break;
            if(list.size() >= index+1)
                index++;
        }

        tempIndex++;

        if(tempIndex == declaration.size() && list.size()-1 >= index+1)
        {
            tempIndex = 0;
            declaration = list[index];
            index++;
        }
    }


    if(list.size()-1 >= index && list[index] == ":")
    {
        index++;

        foreach(const QString &returnType, list.mid(index, list.size()-index))
        {
            if(returnType != ":" && returnType != "{")
            {
                function.prototype.returnType.type = returnType;
                break;
            }
        }
    }

    if(function.prototype.returnType.type.isEmpty())
        qDebug()<<"Function"<<function.prototype.name;

    else
        qDebug()<<"Function"<<function.prototype.name+" - ("+function.prototype.returnType.type+")";

    foreach(const Variable &temp, function.prototype.parameters)
        qDebug()<<"Param :"<<temp.type<<temp.name<<temp.value;

    m_functions<<function;
}

void Splitter::readContent(QString line, int brackets)
{
    for(int i = 0; i < brackets; i++)
        m_functions.last().content += ' ';

    m_functions.last().content += line;
    m_functions.last().content += '\n';
}

void Splitter::readClassVariable(QString line)
{
    ClassVariable variable;
    line.remove(";");
    QStringList list = line.split(' ');

    int index = list.indexOf("var")+1;

    if(index == 0)
        index = list.indexOf("const")+1;

    QStringList tempList = list[index].split(':');
    variable.variable.name = tempList[0];


    int brackets = 0;

    for(int i = 0; i < tempList[1].size(); i++)
    {
        if(tempList[1][i] == '<')
        {
            if(brackets == 0)
            {
                brackets++;
                continue;
            }

            else
                brackets++;
        }

        else if(tempList[1][i] == '>')
        {
            if(brackets == 1)
            {
                brackets--;
                continue;
            }

            else
                brackets--;
        }

        if(tempList[1][i] != ' ' && tempList[1][i] != ';')
        {
            if(brackets == 0 && tempList[1][i] != '.')
                variable.variable.type += tempList[1][i];

            else if(brackets > 0)
            {
                variable.variable.isContainer = true;
                variable.variable.containerShell.type += tempList[1][i];
            }
        }

    }


    if(list.contains("="))
        variable.variable.value = list[list.size()-1];

    if(list.contains("public"))
        variable.inheritance = PUBLIC;

    else if(list.contains("private"))
        variable.inheritance = PRIVATE;

    else if(list.contains("protected"))
        variable.inheritance = PROTECTED;

    else
        qDebug()<<"SPLITTER - ERREUR - Inheritance";

    if(list.contains("const"))
        variable.variable.isConstant = true;

    m_variables<<variable;

    qDebug()<<"ClassVariable"<<variable.variable.type<<variable.variable.containerShell.type<<variable.variable.name<<variable.variable.value;
}

QList<QString> Splitter::getIncludes() const
{
    return m_includes;
}

ClassInfos Splitter::getClassInfos() const
{
    return m_classInfos;
}

QList<FunctionData> Splitter::getFunctions() const
{
    return m_functions;
}

QList<ClassVariable> Splitter::getClassVariables() const
{
    return m_variables;
}
