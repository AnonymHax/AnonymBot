#include "BasicWhoIsNoMatchMessage.h"

void BasicWhoIsNoMatchMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicWhoIsNoMatchMessage(param1);
}

void BasicWhoIsNoMatchMessage::serializeAs_BasicWhoIsNoMatchMessage(Writer *param1)
{
  param1->writeUTF(this->search);
}

void BasicWhoIsNoMatchMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicWhoIsNoMatchMessage(param1);
}

void BasicWhoIsNoMatchMessage::deserializeAs_BasicWhoIsNoMatchMessage(Reader *param1)
{
  this->search = param1->readUTF();
}

BasicWhoIsNoMatchMessage::BasicWhoIsNoMatchMessage()
{
  m_type = MessageEnum::BASICWHOISNOMATCHMESSAGE;
}

