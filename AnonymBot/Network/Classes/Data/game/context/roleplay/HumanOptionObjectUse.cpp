#include "HumanOptionObjectUse.h"

void HumanOptionObjectUse::serialize(Writer *param1)
{
  this->serializeAs_HumanOptionObjectUse(param1);
}

void HumanOptionObjectUse::serializeAs_HumanOptionObjectUse(Writer *param1)
{
  HumanOption::serializeAs_HumanOption(param1);
  param1->writeByte(this->delayTypeId);
  if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayEndTime << ") on element delayEndTime.";
  }
  else
  {
    param1->writeDouble(this->delayEndTime);
    if(this->objectGID < 0)
    {
      qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->objectGID << ") on element objectGID.";
    }
    else
    {
      param1->writeVarShort((int)this->objectGID);
      return;
    }
  }
}

void HumanOptionObjectUse::deserialize(Reader *param1)
{
  this->deserializeAs_HumanOptionObjectUse(param1);
}

void HumanOptionObjectUse::deserializeAs_HumanOptionObjectUse(Reader *param1)
{
  HumanOption::deserialize(param1);
  this->delayTypeId = param1->readByte();
  if(this->delayTypeId < 0)
  {
    qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayTypeId << ") on element of HumanOptionObjectUse.delayTypeId.";
  }
  else
  {
    this->delayEndTime = param1->readDouble();
    if(this->delayEndTime < 0 || this->delayEndTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->delayEndTime << ") on element of HumanOptionObjectUse.delayEndTime.";
    }
    else
    {
      this->objectGID = param1->readVarUhShort();
      if(this->objectGID < 0)
      {
        qDebug()<<"ERREUR - HumanOptionObjectUse -"<<"Forbidden value (" << this->objectGID << ") on element of HumanOptionObjectUse.objectGID.";
      }
      else
      {
        return;
      }
    }
  }
}

HumanOptionObjectUse::HumanOptionObjectUse()
{
  m_types<<ClassEnum::HUMANOPTIONOBJECTUSE;
}

bool HumanOptionObjectUse::operator==(const HumanOptionObjectUse &compared)
{
  if(delayTypeId == compared.delayTypeId)
  if(delayEndTime == compared.delayEndTime)
  if(objectGID == compared.objectGID)
  return true;
  
  return false;
}

