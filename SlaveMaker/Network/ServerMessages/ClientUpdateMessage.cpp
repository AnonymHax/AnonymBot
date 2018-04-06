#include "ClientUpdateMessage.h"

ClientUpdateMessage::ClientUpdateMessage()
{
    m_type = ServerMessageEnum::CLIENTUPDATEMESSAGE;
}

void ClientUpdateMessage::serialize(Writer *writer)
{
    writer->writeUInt(nbActiveBots);
}

void ClientUpdateMessage::deserialize(Reader *reader)
{
    nbActiveBots = reader->readUInt();
}
