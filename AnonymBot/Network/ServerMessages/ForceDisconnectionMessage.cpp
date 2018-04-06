#include "ForceDisconnectionMessage.h"

ForceDisconnectionMessage::ForceDisconnectionMessage()
{
    m_type = ServerMessageEnum::FORCEDISCONNECTIONMESSAGE;
}

void ForceDisconnectionMessage::serialize(Writer *writer)
{
    writer->writeInt((int)reason);
}

void ForceDisconnectionMessage::deserialize(Reader *reader)
{
    reason = (FailureReasonsEnum)reader->readInt();
}
