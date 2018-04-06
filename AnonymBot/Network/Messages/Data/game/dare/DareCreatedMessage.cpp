#include "DareCreatedMessage.h"

void DareCreatedMessage::serialize(Writer *param1)
{
  this->serializeAs_DareCreatedMessage(param1);
}

void DareCreatedMessage::serializeAs_DareCreatedMessage(Writer *param1)
{
  this->dareInfos.serializeAs_DareInformations(param1);
  param1->writeBool(this->needNotifications);
}

void DareCreatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareCreatedMessage(param1);
}

void DareCreatedMessage::deserializeAs_DareCreatedMessage(Reader *param1)
{
  this->dareInfos = DareInformations();
  this->dareInfos.deserialize(param1);
  this->needNotifications = param1->readBool();
}

DareCreatedMessage::DareCreatedMessage()
{
  m_type = MessageEnum::DARECREATEDMESSAGE;
}

