#ifndef CLASSDECLARATOR_H
#define CLASSDECLARATOR_H

#include "Public.h"
#include "ClassLocalizer.h"

class ClassDeclarator : public AbstractSerializer
{
public:
    ClassDeclarator(const QString &output, ClassLocalizer *localizer);

    void serialize();
    void write();

private:
    QString m_fileName;
    QByteArray m_content;
    ClassLocalizer *m_localizer;
};

#endif // CLASSDECLARATOR_H
