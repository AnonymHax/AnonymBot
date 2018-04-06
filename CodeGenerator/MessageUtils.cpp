#include "MessageUtils.h"

MessageUtils::MessageUtils(const QString &output, MessageLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer)
{
}

MessageUtils::~MessageUtils()
{
    if(m_source)
        delete m_source;
}

void MessageUtils::serialize()
{
    ClassInfos classInfos;
    classInfos.name = MESSAGE_UTILS_NAME;

    m_source = new SourceSerializer(m_output+"/"+MESSAGE_UTILS_PATH, classInfos);

    m_source->getHeader().addInclude(QString(PUBLIC_PATH));
    m_source->getHeader().addInclude(QString(MESSAGE_UTILS_PATH)+"/"+QString(MESSAGE_ENUM_NAME)+".h");

    FunctionData getName;
    getName.prototype.name = "getName";
    getName.prototype.isStatic = true;
    Variable parameter;
    parameter.name = "messageEnum";
    parameter.isConstant = true;
    parameter.link = LinkType::REFERENCE;
    parameter.type = "MessageEnum";
    getName.prototype.parameters<<parameter;
    getName.prototype.returnType.type = "QString";

    QTextStream nameOut(&getName.content, QIODevice::WriteOnly);

    bool isFirst = true;

    foreach(const MessageTranslator &child, m_localizer->getChildren())
    {
        if(isFirst)
            isFirst = false;

        else
            nameOut<<"\nelse ";

        nameOut<<"if(messageEnum == "<<QString(MESSAGE_ENUM_NAME)<<"::"<<child.getName().toUpper()<<")";
        nameOut<<"\n    return \""<<child.getName()<<"\";";
        nameOut<<"\n";
    }

    nameOut<<"\nelse";
    nameOut<<"\n{";
    nameOut<<"\nqDebug()<<\"ERREUR - "<<MESSAGE_UTILS_NAME<<" - Ne connait pas l'enum :\"<<(int)messageEnum;";
    nameOut<<"\nreturn \"\";";
    nameOut<<"\n}";

    m_source->addFunction(getName);

    m_source->serialize();
}

void MessageUtils::write()
{
    m_source->write();
}
