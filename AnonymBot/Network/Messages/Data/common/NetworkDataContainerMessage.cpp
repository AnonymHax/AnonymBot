#include "NetworkDataContainerMessage.h"

void NetworkDataContainerMessage::serialize(Writer *param1)
{
  this->serializeAs_NetworkDataContainerMessage(param1);
}

void NetworkDataContainerMessage::serializeAs_NetworkDataContainerMessage(Writer *param1)
{
  param1->writeBytes(this->content);
  qDebug()<<"ERREUR - NetworkDataContainerMessage -"<<"Not implemented";
}

void NetworkDataContainerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NetworkDataContainerMessage(param1);
}

void NetworkDataContainerMessage::deserializeAs_NetworkDataContainerMessage(Reader *param1)
{
  uint _loc2_ = param1->readVarInt();
  QByteArray _loc3_ = QByteArray();
  _loc3_ = param1->readBytes();
  _loc3_ = gUncompress(_loc3_);
  this->content = _loc3_;
}

NetworkDataContainerMessage::NetworkDataContainerMessage()
{
  m_type = MessageEnum::NETWORKDATACONTAINERMESSAGE;
}

