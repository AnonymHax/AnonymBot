#include "ProtectedEntityWaitingForHelpInfo.h"

void ProtectedEntityWaitingForHelpInfo::serialize(Writer *param1)
{
  this->serializeAs_ProtectedEntityWaitingForHelpInfo(param1);
}

void ProtectedEntityWaitingForHelpInfo::serializeAs_ProtectedEntityWaitingForHelpInfo(Writer *param1)
{
  param1->writeInt((int)this->timeLeftBeforeFight);
  param1->writeInt((int)this->waitTimeForPlacement);
  if(this->nbPositionForDefensors < 0)
  {
    qDebug()<<"ERREUR - ProtectedEntityWaitingForHelpInfo -"<<"Forbidden value (" << this->nbPositionForDefensors << ") on element nbPositionForDefensors.";
  }
  else
  {
    param1->writeByte(this->nbPositionForDefensors);
    return;
  }
}

void ProtectedEntityWaitingForHelpInfo::deserialize(Reader *param1)
{
  this->deserializeAs_ProtectedEntityWaitingForHelpInfo(param1);
}

void ProtectedEntityWaitingForHelpInfo::deserializeAs_ProtectedEntityWaitingForHelpInfo(Reader *param1)
{
  this->timeLeftBeforeFight = param1->readInt();
  this->waitTimeForPlacement = param1->readInt();
  this->nbPositionForDefensors = param1->readByte();
  if(this->nbPositionForDefensors < 0)
  {
    qDebug()<<"ERREUR - ProtectedEntityWaitingForHelpInfo -"<<"Forbidden value (" << this->nbPositionForDefensors << ") on element of ProtectedEntityWaitingForHelpInfo.nbPositionForDefensors.";
  }
  else
  {
    return;
  }
}

ProtectedEntityWaitingForHelpInfo::ProtectedEntityWaitingForHelpInfo()
{
  m_types<<ClassEnum::PROTECTEDENTITYWAITINGFORHELPINFO;
}

bool ProtectedEntityWaitingForHelpInfo::operator==(const ProtectedEntityWaitingForHelpInfo &compared)
{
  if(timeLeftBeforeFight == compared.timeLeftBeforeFight)
  if(waitTimeForPlacement == compared.waitTimeForPlacement)
  if(nbPositionForDefensors == compared.nbPositionForDefensors)
  return true;
  
  return false;
}

