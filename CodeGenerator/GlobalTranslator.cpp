#include "GlobalTranslator.h"

GlobalTranslator::GlobalTranslator(const QString &input, const QString &output, TranslationPart translationPart) :
    AbstractParser(input),
    AbstractSerializer(output),
    m_translationPart(translationPart),
    m_enumLocalizer(input, output),
    m_enumDeclarator(output, &m_enumLocalizer),
    m_classLocalizer(input, output),
    m_classDeclarator(output, &m_classLocalizer),
    m_classEnum(output, &m_classLocalizer),
    m_classManager(input, output, &m_classLocalizer),
    m_messageLocalizer(input, output),
    m_messageDeclarator(output, &m_messageLocalizer),
    m_messageEnum(output, &m_messageLocalizer),
    m_messageUtils(output, &m_messageLocalizer),
    m_dataLocalizer(input, output),
    m_dataDeclarator(output, &m_dataLocalizer),
    m_dataTypeDeclarator(output, &m_dataLocalizer),
    m_dataConverter(output, &m_dataLocalizer)
{
}

void GlobalTranslator::parse()
{    
    qDebug()<<"GlobalTranslator - Parsing...";

    if(m_translationPart == TRANSLATION_1)
         m_dataLocalizer.parse();

    else if(m_translationPart == TRANSLATION_2)
    {
        m_enumLocalizer.parse();

        m_classManager.parse();
        m_classLocalizer.parse();

        m_messageLocalizer.parse();
    }
}

void GlobalTranslator::serialize()
{
    qDebug()<<"GlobalTranslator - Serialization...";

    if(m_translationPart == TRANSLATION_1)
    {
        m_dataLocalizer.serialize();
        m_dataDeclarator.serialize();
        m_dataTypeDeclarator.serialize();
        m_dataConverter.serialize();
    }

    else if(m_translationPart == TRANSLATION_2)
    {
        m_enumLocalizer.serialize();
        m_enumDeclarator.serialize();

        m_classLocalizer.serialize();
        m_classDeclarator.serialize();
        m_classEnum.serialize();
        m_classManager.serialize();

        m_messageLocalizer.serialize();
        m_messageDeclarator.serialize();
        m_messageEnum.serialize();
        m_messageUtils.serialize();
    }
}

void GlobalTranslator::write()
{
    qDebug()<<"GlobalTranslator - Writing...";

    if(m_translationPart == TRANSLATION_1)
    {
        m_dataLocalizer.write();
        m_dataDeclarator.write();
        m_dataTypeDeclarator.write();
        m_dataConverter.write();
    }

    else if(m_translationPart == TRANSLATION_2)
    {
        m_enumLocalizer.write();
        m_enumDeclarator.write();

        m_classLocalizer.write();
        m_classDeclarator.write();
        m_classEnum.write();
        m_classManager.write();

        m_messageLocalizer.write();
        m_messageDeclarator.write();
        m_messageEnum.write();
        m_messageUtils.write();
    }
}
