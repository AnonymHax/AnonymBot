#ifndef DATATYPEDECLARATOR_H
#define DATATYPEDECLARATOR_H

#include "Public.h"
#include "AbstractSerializer.h"
#include "DataLocalizer.h"

class DataTypeDeclarator : public AbstractSerializer
{
public:
    DataTypeDeclarator(const QString &output, DataLocalizer *localizer);

    virtual void serialize();
    virtual void write();

private:
    QString m_fileName;
    QByteArray m_content;
    DataLocalizer *m_localizer;
};

#endif // DATATYPEDECLARATOR_H
