#include "StatsUpgradeRequestMessage.h"

void StatsUpgradeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_StatsUpgradeRequestMessage(param1);
}

void StatsUpgradeRequestMessage::serializeAs_StatsUpgradeRequestMessage(Writer *param1)
{
  param1->writeBool(this->useAdditionnal);
  param1->writeByte(this->statId);
  if(this->boostPoint < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->boostPoint << ") on element boostPoint.";
  }
  else
  {
    param1->writeVarShort((int)this->boostPoint);
    return;
  }
}

void StatsUpgradeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StatsUpgradeRequestMessage(param1);
}

void StatsUpgradeRequestMessage::deserializeAs_StatsUpgradeRequestMessage(Reader *param1)
{
  this->useAdditionnal = param1->readBool();
  this->statId = param1->readByte();
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->statId << ") on element of StatsUpgradeRequestMessage.statId.";
  }
  else
  {
    this->boostPoint = param1->readVarUhShort();
    if(this->boostPoint < 0)
    {
      qDebug()<<"ERREUR - StatsUpgradeRequestMessage -"<<"Forbidden value (" << this->boostPoint << ") on element of StatsUpgradeRequestMessage.boostPoint.";
    }
    else
    {
      return;
    }
  }
}

StatsUpgradeRequestMessage::StatsUpgradeRequestMessage()
{
  m_type = MessageEnum::STATSUPGRADEREQUESTMESSAGE;
}

