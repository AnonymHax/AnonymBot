#include "HumanOptionEmote.h"

void HumanOptionEmote::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionEmote(param1);
}

void HumanOptionEmote::serializeAs_HumanOptionEmote(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteStartTime << ") on element emoteStartTime.";
    }
    else
    {
      param1->writeDouble(this->emoteStartTime);
      return;
    }
  }
}

void HumanOptionEmote::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionEmote(param1);
}

void HumanOptionEmote::deserializeAs_HumanOptionEmote(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteId << ") on element of HumanOptionEmote.emoteId.";
  }
  else
  {
    this->emoteStartTime = param1->readDouble();
    if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - HumanOptionEmote -"<<"Forbidden value (" << this->emoteStartTime << ") on element of HumanOptionEmote.emoteStartTime.";
    }
    else
    {
      return;
    }
  }
}

HumanOptionEmote::HumanOptionEmote()
{
  m_types<<ClassEnum::HUMANOPTIONEMOTE;
}

bool HumanOptionEmote::operator==(const HumanOptionEmote &compared)
{
  if(emoteId == compared.emoteId)
  if(emoteStartTime == compared.emoteStartTime)
  return true;
  
  return false;
}

