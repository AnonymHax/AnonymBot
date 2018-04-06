#ifndef ABSTRACTMESSAGE_H
#define ABSTRACTMESSAGE_H

#include "Network/Messages/MessageEnum.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"

class AbstractMessage
{
public:
    AbstractMessage()
    {m_needsHash = false;}
    virtual void serialize(Writer *writer) = 0;
    virtual void deserialize(Reader *reader) = 0;
    bool needHash() const
    {return m_needsHash;}
    MessageEnum getType() const
    {return m_type;}
    virtual ~AbstractMessage()
    {}

protected:
    bool m_needsHash;
    MessageEnum m_type;
};

#endif // ABSTRACTMESSAGE_H
