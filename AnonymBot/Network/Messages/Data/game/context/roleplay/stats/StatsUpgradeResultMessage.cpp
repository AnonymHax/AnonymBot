#include "StatsUpgradeResultMessage.h"

void StatsUpgradeResultMessage::serialize(Writer *param1)
{
  this->serializeAs_StatsUpgradeResultMessage(param1);
}

void StatsUpgradeResultMessage::serializeAs_StatsUpgradeResultMessage(Writer *param1)
{
  param1->writeByte(this->result);
  if(this->nbCharacBoost < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeResultMessage -"<<"Forbidden value (" << this->nbCharacBoost << ") on element nbCharacBoost.";
  }
  else
  {
    param1->writeVarShort((int)this->nbCharacBoost);
    return;
  }
}

void StatsUpgradeResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StatsUpgradeResultMessage(param1);
}

void StatsUpgradeResultMessage::deserializeAs_StatsUpgradeResultMessage(Reader *param1)
{
  this->result = param1->readByte();
  this->nbCharacBoost = param1->readVarUhShort();
  if(this->nbCharacBoost < 0)
  {
    qDebug()<<"ERREUR - StatsUpgradeResultMessage -"<<"Forbidden value (" << this->nbCharacBoost << ") on element of StatsUpgradeResultMessage.nbCharacBoost.";
  }
  else
  {
    return;
  }
}

StatsUpgradeResultMessage::StatsUpgradeResultMessage()
{
  m_type = MessageEnum::STATSUPGRADERESULTMESSAGE;
}

