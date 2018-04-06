#include "ConnectionFailureMessage.h"

ConnectionFailureMessage::ConnectionFailureMessage()
{
    m_type = ServerMessageEnum::CONNECTIONFAILUREMESSAGE;
}

void ConnectionFailureMessage::serialize(Writer *writer)
{
    writer->writeInt((int)reason);
}

void ConnectionFailureMessage::deserialize(Reader *reader)
{
    reason = (FailureReasonsEnum)reader->readInt();
}
