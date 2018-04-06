#include "BasicWhoAmIRequestMessage.h"

void BasicWhoAmIRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicWhoAmIRequestMessage(param1);
}

void BasicWhoAmIRequestMessage::serializeAs_BasicWhoAmIRequestMessage(Writer *param1)
{
  param1->writeBool(this->verbose);
}

void BasicWhoAmIRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicWhoAmIRequestMessage(param1);
}

void BasicWhoAmIRequestMessage::deserializeAs_BasicWhoAmIRequestMessage(Reader *param1)
{
  this->verbose = param1->readBool();
}

BasicWhoAmIRequestMessage::BasicWhoAmIRequestMessage()
{
  m_type = MessageEnum::BASICWHOAMIREQUESTMESSAGE;
}

