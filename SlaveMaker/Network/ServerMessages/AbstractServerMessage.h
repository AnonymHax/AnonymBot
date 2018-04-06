#ifndef ABSTRACTSERVERMESSAGE_H
#define ABSTRACTSERVERMESSAGE_H

#include "Public.h"
#include "IO/Reader.h"
#include "ServerMessageEnum.h"
#include "IO/Writer.h"

class AbstractServerMessage
{
public:
    virtual void serialize(Writer *writer) = 0;
    virtual void deserialize(Reader *reader) = 0;
    ServerMessageEnum getType() const
    {return m_type;}
    virtual ~AbstractServerMessage()
    {}

protected:
    ServerMessageEnum m_type;
};

#endif // ABSTRACTSERVERMESSAGE_H
