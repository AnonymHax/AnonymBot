#include "RawResolveRequestMessage.h"

RawResolveRequestMessage::RawResolveRequestMessage()
{
    m_type = ServerMessageEnum::RAWRESOLVEREQUESTMESSAGE;
}

void RawResolveRequestMessage::serialize(Writer *writer)
{
    writer->writeInt(index);
    writer->writeUTF(ticket);
    writer->writeInt(content.size());
    writer->writeBytes(content);
}

void RawResolveRequestMessage::deserialize(Reader *reader)
{
    index = reader->readInt();
    ticket = reader->readUTF();

    int size = reader->readInt();

    content.clear();
    content.reserve(size);

    for(int i = 0; i < size; i++)
        content[i] = reader->readByte();
}
