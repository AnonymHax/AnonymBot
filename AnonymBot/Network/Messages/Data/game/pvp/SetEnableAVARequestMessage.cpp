#include "SetEnableAVARequestMessage.h"

void SetEnableAVARequestMessage::serialize(Writer *param1)
{
  this->serializeAs_SetEnableAVARequestMessage(param1);
}

void SetEnableAVARequestMessage::serializeAs_SetEnableAVARequestMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void SetEnableAVARequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SetEnableAVARequestMessage(param1);
}

void SetEnableAVARequestMessage::deserializeAs_SetEnableAVARequestMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

SetEnableAVARequestMessage::SetEnableAVARequestMessage()
{
  m_type = MessageEnum::SETENABLEAVAREQUESTMESSAGE;
}

