#include "DataConverter.h"

DataConverter::DataConverter(const QString &output, DataLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer)
{
}

DataConverter::~DataConverter()
{
    if(m_source)
        delete m_source;
}

void DataConverter::serialize()
{
    ClassInfos classInfos;
    classInfos.name = DATA_CONVERTER_NAME;

    m_source = new SourceSerializer(m_output+"/"+DATA_UTILS_PATH, classInfos);

      m_source->getHeader().addInclude(QString(DATA_UTILS_PATH)+"/"+QString(DATA_DECLARATOR_NAME)+".h");
    m_source->getHeader().addInclude(QString(DATA_UTILS_PATH)+"/"+QString(DATA_TYPE_DECLARATOR_NAME )+".h");

    FunctionData getClass;
    getClass.prototype.name = "getClass";
    getClass.prototype.isStatic = true;
    getClass.prototype.returnType.type = QString(DATA_BASE_NAME);
    getClass.prototype.returnType.link = SHARED_POINTER;
    Variable parameter;
    parameter.type = "QString";
    parameter.name = "name";
    parameter.isConstant = true;
    parameter.link = REFERENCE;
    getClass.prototype.parameters<<parameter;

    QTextStream classOut(&getClass.content, QIODevice::WriteOnly);

    bool isFirst = true;

    foreach(const DataTranslator &child, m_localizer->getChildren())
    {
        if(isFirst)
            isFirst = false;

        else
            classOut<<"\nelse ";

        classOut<<"if(name == \""<<child.getDofusName()<<"\")";
        classOut<<"\n    return QSharedPointer<"<<DATA_BASE_NAME<<">(new "<<child.getName()<<"());";
        classOut<<"\n";
    }

    foreach(const DataTranslator &child, m_localizer->getUselessChildren())
    {
        if(isFirst)
            isFirst = false;

        else
            classOut<<"\nelse ";

        classOut<<"if(name == \""<<child.getDofusName()<<"\")";
        classOut<<"\n    return QSharedPointer<"<<DATA_BASE_NAME<<">(NULL);";
        classOut<<"\n";
    }

    classOut<<"\nelse";
    classOut<<"\n{";
    classOut<<"\nqDebug()<<\"ERREUR - "<<DATA_CONVERTER_NAME<<" - Ne connait pas la classe :\"<<name;";
    classOut<<"\nreturn QSharedPointer<"<<DATA_BASE_NAME<<">(NULL);";
    classOut<<"\n}";

    m_source->addFunction(getClass);

    FunctionData getEnum;
    getEnum.prototype.name = "getEnum";
    getEnum.prototype.isStatic = true;
    getEnum.prototype.returnType.type = QString(DATA_ENUM_TYPE_NAME);
    getEnum.prototype.parameters<<parameter;

    QTextStream enumOut(&getEnum.content, QIODevice::WriteOnly);


    isFirst = true;

    foreach(const DataTranslator &child, m_localizer->getChildren())
    {
        if(!child.getModule().isEmpty())
        {
            if(isFirst)
                isFirst = false;

            else
                enumOut<<"\nelse ";

            enumOut<<"if(name == \""<<child.getModule()<<"\")";
            enumOut<<"\n    return "+QString(DATA_ENUM_TYPE_NAME)+"::"+child.getModule().toUpper()+";";
            enumOut<<"\n";
        }
    }

    foreach(const DataTranslator &child, m_localizer->getUselessChildren())
    {
            if(isFirst)
                isFirst = false;

            else
                enumOut<<"\nelse ";

            enumOut<<"if(name == \""<<child.getModule()<<"\")";
            enumOut<<"\n    return "+QString(DATA_ENUM_TYPE_NAME)+"::UNKNOWN;";
            enumOut<<"\n";
    }

    enumOut<<"\nelse";
    enumOut<<"\n{";
    enumOut<<"\nqDebug()<<\"ERREUR - "<<DATA_CONVERTER_NAME<<" - Ne connait pas l'enum :\"<<name;";
    enumOut<<"\nreturn "+QString(DATA_ENUM_TYPE_NAME)+"::UNKNOWN;";
    enumOut<<"\n}";

    m_source->addFunction(getEnum);

    m_source->serialize();
}

void DataConverter::write()
{
    m_source->write();
}
