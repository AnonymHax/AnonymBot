#ifndef ABSTRACTSERIALIZER_H
#define ABSTRACTSERIALIZER_H

#include "Public.h"

class AbstractSerializer
{
public:
    AbstractSerializer(const QString &output);
    virtual ~AbstractSerializer();

    virtual void serialize() = 0;
    virtual void write() = 0;

    QString getOutput() const;

protected:
    QString m_output;
};

#endif // ABSTRACTSERIALIZER_H
