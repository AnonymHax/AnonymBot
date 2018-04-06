#include "RawResolveMessage.h"

RawResolveMessage::RawResolveMessage()
{
    m_type = ServerMessageEnum::RAWRESOLVEMESSAGE;
}

void RawResolveMessage::serialize(Writer *writer)
{
    writer->writeInt(index);
    writer->writeInt(data.size());

    for(int i = 0; i < data.size(); i++)
        writer->writeInt(data[i]);
}

void RawResolveMessage::deserialize(Reader *reader)
{
    data.clear();
    index = reader->readInt();
    int size = reader->readInt();

    for(int i = 0; i < size; i++)
        data<<reader->readInt();
}
