#include "ClassTranslator.h"

ClassTranslator::ClassTranslator(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output),
    m_splitter(input),
    m_source(NULL),
    m_id(-1)
{
}

ClassTranslator::~ClassTranslator()
{
    if(m_source)
        delete m_source;
}

void ClassTranslator::parse()
{
    m_splitter.parse();

    foreach(const FunctionData &funct, m_splitter.getFunctions())
    {
        if(funct.prototype.name == "getTypeId")
        {
            m_id = funct.content.split(" ", QString::SkipEmptyParts)[1].split(";", QString::SkipEmptyParts)[0].toInt();
            break;
        }
    }

    foreach(const ClassVariable &var, m_splitter.getClassVariables())
    {
        if(Translator::isTranslated(var.variable.type) && !m_missingIncludes.contains(var.variable.type))
            m_missingIncludes<<var.variable.type;

        if(Translator::isTranslated(var.variable.containerShell.type) && !m_missingIncludes.contains(var.variable.containerShell.type))
            m_missingIncludes<<var.variable.containerShell.type;
    }

    ClassInfos classInfos = m_splitter.getClassInfos();

    for(int i = 0; i < classInfos.inheritedClasses.size(); i++)
    {
        if(Translator::isTranslated(classInfos.inheritedClasses[i].name) &&
                !m_missingIncludes.contains(classInfos.inheritedClasses[i].name))
            m_missingIncludes<<classInfos.inheritedClasses[i].name;
    }
}

void ClassTranslator::serialize()
{
    ClassInfos classInfos = m_splitter.getClassInfos();

    for(int i = 0; i < classInfos.inheritedClasses.size(); i++)
    {
        if(!Translator::isTranslated(classInfos.inheritedClasses[i].name))
        {
            if(!Translator::isKnown(classInfos.inheritedClasses[i].name))
                qDebug()<<"ERREUR - ClassTranslator - Ne connait pas"<<classInfos.inheritedClasses[i].name<<"herité par la classe"<<getName();

            classInfos.inheritedClasses.removeAt(i);
            i--;
        }
    }

    if(classInfos.inheritedClasses.isEmpty())
    {
        InheritedClass baseClass;
        baseClass.name = CLASS_BASE_NAME;
        classInfos.inheritedClasses<<baseClass;
    }

    m_source = new SourceSerializer(m_output, classInfos);

    m_source->getHeader().addInclude(QString(CLASS_UTILS_PATH)+"/"+QString(CLASS_BASE_NAME)+".h");

    foreach(const QString &include, m_manualIncludes)
        m_source->getHeader().addInclude(include);

    for(int i = 0; i < m_anticipatedDeclarations.size(); i++)
    {
        m_source->getHeader().addImplicitClass(m_anticipatedDeclarations[i].first);
        m_source->addInclude(m_anticipatedDeclarations[i].second);
    }

    foreach(const QString &include, m_splitter.getIncludes())
    {
        QString translated = Translator::translateInclude(include);

        if(!translated.isEmpty())
            m_source->getHeader().addInclude(translated);
    }

    QStringList content;

    foreach(const FunctionData &funct, m_splitter.getFunctions())
    {
        if(funct.prototype.name.contains("serialize"))
        {
            ConversionFunction conversionFunct;
            conversionFunct. isSelfActionNotDetainedByClass = false;
            conversionFunct.originalName = funct.prototype.name;
            conversionFunct.translatedName = funct.prototype.name;
            conversionFunct.parameters<<"#0#";
            Translator::addFunction(m_splitter.getClassInfos().name, conversionFunct);
        }

        else if(funct.prototype.name == "getTypeId")
        {
            ConversionFunction conversionFunct;
            conversionFunct. isSelfActionNotDetainedByClass = false;
            conversionFunct.originalName = funct.prototype.name;
            conversionFunct.translatedName = "getTypes().last";
            Translator::addFunction(m_splitter.getClassInfos().name, conversionFunct);
        }
    }

    foreach(const FunctionData &funct, m_splitter.getFunctions())
    {
        if(funct.prototype.name.contains("serialize"))
        {
            FunctionData translated = Translator::translateFunction(funct, m_splitter.getClassVariables(), classInfos);

            if(funct.prototype.name == "serialize" || funct.prototype.name == "deserialize")
                translated.prototype.isVirtual = true;

            m_source->addFunction(translated);
            content<<translated.content;
        }
    }

    FunctionData constructor;
    constructor.prototype.name = m_splitter.getClassInfos().name;

    QTextStream outConstructor(&constructor.content, QIODevice::WriteOnly);

    outConstructor<<"m_types<<"<<CLASS_ENUM_NAME<<"::"<<getName().toUpper()<<";\n";

    FunctionData egalOperator;
    egalOperator.prototype.name = "operator==";
    egalOperator.prototype.returnType.type = "bool";
    Variable parameter;
    parameter.name = "compared";
    parameter.type = classInfos.name;
    parameter.isConstant = true;
    parameter.link = REFERENCE;
    egalOperator.prototype.parameters<<parameter;
    bool hasPointers = false;

    QTextStream outOperator(&egalOperator.content, QIODevice::WriteOnly);

    foreach(const ClassVariable &variable, m_splitter.getClassVariables())
    {
        if(!content.filter(variable.variable.name).isEmpty())
        {
            hasPointers = true;

            ClassVariable translatedVariable = Translator::translateClassVariable(variable);

            m_source->getHeader().addClassVariable(translatedVariable);

            outOperator<<"if(";

            if(translatedVariable.variable.link == POINTER)
                outOperator<<"*";

            outOperator<<translatedVariable.variable.name<<" == ";

            if(translatedVariable.variable.link == POINTER)
                outOperator<<"*";

            outOperator<<"compared."<<translatedVariable.variable.name<<")\n";
        }
    }

    outOperator<<"return true;";

    if(hasPointers)
        outOperator<<"\n\nreturn false;\n";

    if(!constructor.content.isEmpty())
        m_source->addFunction(constructor);

    m_source->addFunction(egalOperator);

    m_source->serialize();
}

void ClassTranslator::write()
{
    m_source->write();
}

void ClassTranslator::addManualInclude(QString include)
{
    if(!m_manualIncludes.contains(include))
        m_manualIncludes<<include;
}

void ClassTranslator::addAnticipatedDeclaration(QString className, QString include)
{
    QPair<QString, QString> pair;
    pair.first = className;
    pair.second = include;
    m_anticipatedDeclarations<<pair;
}

QStringList ClassTranslator::getMissingIncludes() const
{
    return m_missingIncludes;
}

QString ClassTranslator::getName() const
{
    return m_splitter.getClassInfos().name;
}

int ClassTranslator::getId() const
{
    return m_id;
}

QList<ClassVariable> ClassTranslator::getClassVariables() const
{
    return m_splitter.getClassVariables();
}

QList<InheritedClass> ClassTranslator::getInheritedClasses() const
{
    return m_splitter.getClassInfos().inheritedClasses;
}
