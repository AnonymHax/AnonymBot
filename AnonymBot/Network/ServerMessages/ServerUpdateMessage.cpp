#include "ServerUpdateMessage.h"

ServerUpdateMessage::ServerUpdateMessage()
{
    m_type = ServerMessageEnum::SERVERUPDATEMESSAGE;
}

void ServerUpdateMessage::serialize(Writer *writer)
{
    writer->writeUInt(nbActiveBots);
}

void ServerUpdateMessage::deserialize(Reader *reader)
{
    nbActiveBots = reader->readUInt();
}
