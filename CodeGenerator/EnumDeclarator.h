#ifndef ENUMDECLARATOR_H
#define ENUMDECLARATOR_H

#include "Public.h"
#include "EnumLocalizer.h"

class EnumDeclarator : AbstractSerializer
{
public:
    EnumDeclarator(const QString &output, EnumLocalizer *localizer);

    void serialize();
    void write();

private:
    QString m_fileName;
    EnumLocalizer *m_localizer;
    QByteArray m_content;
};

#endif // ENUMDECLARATOR_H
