#include "ConnectionRequestMessage.h"

ConnectionRequestMessage::ConnectionRequestMessage()
{
    m_type = ServerMessageEnum::CONNECTIONREQUESTMESSAGE;
}

void ConnectionRequestMessage::serialize(Writer *writer)
{
    writer->writeUTF(login);
    writer->writeUTF(password);
}

void ConnectionRequestMessage::deserialize(Reader *reader)
{
    login = reader->readUTF();
    password = reader->readUTF();
}
