#include "BasicPongMessage.h"

void BasicPongMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicPongMessage(param1);
}

void BasicPongMessage::serializeAs_BasicPongMessage(Writer *param1)
{
  param1->writeBool(this->quiet);
}

void BasicPongMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicPongMessage(param1);
}

void BasicPongMessage::deserializeAs_BasicPongMessage(Reader *param1)
{
  this->quiet = param1->readBool();
}

BasicPongMessage::BasicPongMessage()
{
  m_type = MessageEnum::BASICPONGMESSAGE;
}

