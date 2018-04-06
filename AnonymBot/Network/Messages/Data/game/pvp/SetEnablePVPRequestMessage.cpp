#include "SetEnablePVPRequestMessage.h"

void SetEnablePVPRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_SetEnablePVPRequestMessage(param1);
}

void SetEnablePVPRequestMessage::serializeAs_SetEnablePVPRequestMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void SetEnablePVPRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SetEnablePVPRequestMessage(param1);
}

void SetEnablePVPRequestMessage::deserializeAs_SetEnablePVPRequestMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

SetEnablePVPRequestMessage::SetEnablePVPRequestMessage()
{
  m_type = MessageEnum::SETENABLEPVPREQUESTMESSAGE;
}

