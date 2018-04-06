#ifndef DATADECLARATOR_H
#define DATADECLARATOR_H

#include "Public.h"
#include "DataLocalizer.h"

class DataDeclarator : public AbstractSerializer
{
public:
    DataDeclarator(const QString &output, DataLocalizer *localizer);

    virtual void serialize();
    virtual void write();

private:
    QString m_fileName;
    QByteArray m_content;
    DataLocalizer *m_localizer;
};

#endif // DATADECLARATOR_H
