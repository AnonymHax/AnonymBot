#ifndef ABSTRACTDOFUSMESSAGE_H
#define ABSTRACTDOFUSMESSAGE_H

#include "DofusMessageEnum.h"
#include "IO/Writer.h"
#include "IO/Reader.h"

class AbstractDofusMessage
{
public:
    virtual void serialize(Writer *writer) = 0;
    virtual void deserialize(Reader *reader) = 0;
    DofusMessageEnum getType() const
    {return m_type;}
    virtual ~AbstractDofusMessage()
    {}

protected:
    DofusMessageEnum m_type;
};

#endif // ABSTRACTDOFUSMESSAGE_H
