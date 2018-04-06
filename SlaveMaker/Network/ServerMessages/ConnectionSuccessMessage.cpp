#include "ConnectionSuccessMessage.h"

ConnectionSuccessMessage::ConnectionSuccessMessage()
{
    m_type = ServerMessageEnum::CONNECTIONSUCCESSMESSAGE;
}

void ConnectionSuccessMessage::serialize(Writer *writer)
{
    writer->writeInt((int)accountType);
    writer->writeUInt(leftTime);
}

void ConnectionSuccessMessage::deserialize(Reader *reader)
{
    accountType = (AccountTypeEnum)reader->readInt();
    leftTime = reader->readUInt();
}
