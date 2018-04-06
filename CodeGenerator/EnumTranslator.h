#ifndef ENUMTRANSLATOR_H
#define ENUMTRANSLATOR_H

#include "Public.h"
#include "AbstractParser.h"
#include "AbstractSerializer.h"
#include "Splitter.h"
#include "Translator.h"

class EnumTranslator : public AbstractParser, public AbstractSerializer
{
public:
    EnumTranslator(const QString &input, const QString &output);

    virtual void parse();
    virtual void serialize();
    virtual void write();

    QString getName() const;

private:
    Splitter m_splitter;
    QByteArray m_content;
};

#endif // ENUMTRANSLATOR_H
