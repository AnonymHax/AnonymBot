#ifndef CLASSENUM_H
#define CLASSENUM_H

#include "Public.h"
#include "ClassLocalizer.h"

class ClassEnum : public AbstractSerializer
{
public:
    ClassEnum(const QString &output, ClassLocalizer *localizer);

    void serialize();
    void write();

private:
    QString m_fileName;
    QByteArray m_content;
    ClassLocalizer *m_localizer;
};

#endif // CLASSENUM_H
