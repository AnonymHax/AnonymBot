#include "AbstractSerializer.h"

AbstractSerializer::AbstractSerializer(const QString &output):
    m_output(output)
{
}

AbstractSerializer::~AbstractSerializer()
{
}

QString AbstractSerializer::getOutput() const
{
    return m_output;
}
