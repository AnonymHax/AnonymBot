#ifndef GLOBATTRANSLATOR_H
#define GLOBATTRANSLATOR_H

#include "Public.h"
#include "ClassDeclarator.h"
#include "ClassEnum.h"
#include "ClassManager.h"
#include "MessageDeclarator.h"
#include "MessageEnum.h"
#include "MessageUtils.h"
#include "EnumDeclarator.h"
#include "DataDeclarator.h"
#include "DataTypeDeclarator.h"
#include "DataConverter.h"

enum TranslationPart
{
    TRANSLATION_1, TRANSLATION_2
};

class GlobalTranslator : public AbstractParser, public AbstractSerializer
{
public:
    GlobalTranslator(const QString &input, const QString &output, TranslationPart translationPart);

    virtual void parse();
    virtual void serialize();
    virtual void write();

private:
    TranslationPart m_translationPart;

    EnumLocalizer m_enumLocalizer;
    EnumDeclarator m_enumDeclarator;

    ClassLocalizer m_classLocalizer;
    ClassDeclarator m_classDeclarator;
    ClassEnum m_classEnum;
    ClassManager m_classManager;

    MessageLocalizer m_messageLocalizer;
    MessageDeclarator m_messageDeclarator;
    MessageEnum m_messageEnum;
    MessageUtils m_messageUtils;

    DataLocalizer m_dataLocalizer;
    DataDeclarator m_dataDeclarator;
    DataTypeDeclarator m_dataTypeDeclarator;
    DataConverter m_dataConverter;
};

#endif // GLOBATTRANSLATOR_H
