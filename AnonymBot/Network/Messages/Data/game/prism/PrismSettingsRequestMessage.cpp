#include "PrismSettingsRequestMessage.h"

void PrismSettingsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismSettingsRequestMessage(param1);
}

void PrismSettingsRequestMessage::serializeAs_PrismSettingsRequestMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->startDefenseTime < 0)
    {
      qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->startDefenseTime << ") on element startDefenseTime.";
    }
    else
    {
      param1->writeByte(this->startDefenseTime);
      return;
    }
  }
}

void PrismSettingsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismSettingsRequestMessage(param1);
}

void PrismSettingsRequestMessage::deserializeAs_PrismSettingsRequestMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSettingsRequestMessage.subAreaId.";
  }
  else
  {
    this->startDefenseTime = param1->readByte();
    if(this->startDefenseTime < 0)
    {
      qDebug()<<"ERREUR - PrismSettingsRequestMessage -"<<"Forbidden value (" << this->startDefenseTime << ") on element of PrismSettingsRequestMessage.startDefenseTime.";
    }
    else
    {
      return;
    }
  }
}

PrismSettingsRequestMessage::PrismSettingsRequestMessage()
{
  m_type = MessageEnum::PRISMSETTINGSREQUESTMESSAGE;
}

