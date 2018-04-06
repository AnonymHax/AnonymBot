#include "BasicWhoIsRequestMessage.h"

void BasicWhoIsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicWhoIsRequestMessage(param1);
}

void BasicWhoIsRequestMessage::serializeAs_BasicWhoIsRequestMessage(Writer *param1)
{
  param1->writeBool(this->verbose);
  param1->writeUTF(this->search);
}

void BasicWhoIsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicWhoIsRequestMessage(param1);
}

void BasicWhoIsRequestMessage::deserializeAs_BasicWhoIsRequestMessage(Reader *param1)
{
  this->verbose = param1->readBool();
  this->search = param1->readUTF();
}

BasicWhoIsRequestMessage::BasicWhoIsRequestMessage()
{
  m_type = MessageEnum::BASICWHOISREQUESTMESSAGE;
}

