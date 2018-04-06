#ifndef ENUMLOCALIZER_H
#define ENUMLOCALIZER_H

#include "Public.h"
#include "EnumTranslator.h"

class EnumLocalizer : public AbstractParser, public AbstractSerializer
{
public:
    EnumLocalizer(const QString &input, const QString &output);

    virtual void parse();
    virtual void serialize();
    virtual void write();

    const QList<EnumTranslator> &getChildren() const;

private:
    QList<EnumTranslator> m_children;
};

#endif // ENUMLOCALIZER_H
