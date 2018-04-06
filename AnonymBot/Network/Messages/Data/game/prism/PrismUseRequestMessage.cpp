#include "PrismUseRequestMessage.h"

void PrismUseRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismUseRequestMessage(param1);
}

void PrismUseRequestMessage::serializeAs_PrismUseRequestMessage(Writer *param1)
{
  param1->writeByte(this->moduleToUse);
}

void PrismUseRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismUseRequestMessage(param1);
}

void PrismUseRequestMessage::deserializeAs_PrismUseRequestMessage(Reader *param1)
{
  this->moduleToUse = param1->readByte();
  if(this->moduleToUse < 0)
  {
    qDebug()<<"ERREUR - PrismUseRequestMessage -"<<"Forbidden value (" << this->moduleToUse << ") on element of PrismUseRequestMessage.moduleToUse.";
  }
  else
  {
    return;
  }
}

PrismUseRequestMessage::PrismUseRequestMessage()
{
  m_type = MessageEnum::PRISMUSEREQUESTMESSAGE;
}

