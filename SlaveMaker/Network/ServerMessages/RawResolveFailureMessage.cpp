#include "RawResolveFailureMessage.h"

RawResolveFailureMessage::RawResolveFailureMessage()
{
    m_type = ServerMessageEnum::RAWRESOLVEFAILUREMESSAGE;
}

void RawResolveFailureMessage::serialize(Writer *writer)
{
    writer->writeInt(index);
    writer->writeInt((int)reason);
}

void RawResolveFailureMessage::deserialize(Reader *reader)
{
    index = reader->readInt();
    reason = (FailureReasonsEnum)reader->readInt();
}
