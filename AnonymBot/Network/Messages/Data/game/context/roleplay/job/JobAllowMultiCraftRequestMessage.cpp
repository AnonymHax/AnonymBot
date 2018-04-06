#include "JobAllowMultiCraftRequestMessage.h"

void JobAllowMultiCraftRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_JobAllowMultiCraftRequestMessage(param1);
}

void JobAllowMultiCraftRequestMessage::serializeAs_JobAllowMultiCraftRequestMessage(Writer *param1)
{
  param1->writeBool(this->enabled);
}

void JobAllowMultiCraftRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobAllowMultiCraftRequestMessage(param1);
}

void JobAllowMultiCraftRequestMessage::deserializeAs_JobAllowMultiCraftRequestMessage(Reader *param1)
{
  this->enabled = param1->readBool();
}

JobAllowMultiCraftRequestMessage::JobAllowMultiCraftRequestMessage()
{
  m_type = MessageEnum::JOBALLOWMULTICRAFTREQUESTMESSAGE;
}

