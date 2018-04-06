#include "LifePointsRegenEndMessage.h"

void LifePointsRegenEndMessage::serialize(Writer *param1)
{
  this->serializeAs_LifePointsRegenEndMessage(param1);
}

void LifePointsRegenEndMessage::serializeAs_LifePointsRegenEndMessage(Writer *param1)
{
  UpdateLifePointsMessage::serializeAs_UpdateLifePointsMessage(param1);
  if(this->lifePointsGained < 0)
  {
    qDebug()<<"ERREUR - LifePointsRegenEndMessage -"<<"Forbidden value (" << this->lifePointsGained << ") on element lifePointsGained.";
  }
  else
  {
    param1->writeVarInt((int)this->lifePointsGained);
    return;
  }
}

void LifePointsRegenEndMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LifePointsRegenEndMessage(param1);
}

void LifePointsRegenEndMessage::deserializeAs_LifePointsRegenEndMessage(Reader *param1)
{
  UpdateLifePointsMessage::deserialize(param1);
  this->lifePointsGained = param1->readVarUhInt();
  if(this->lifePointsGained < 0)
  {
    qDebug()<<"ERREUR - LifePointsRegenEndMessage -"<<"Forbidden value (" << this->lifePointsGained << ") on element of LifePointsRegenEndMessage.lifePointsGained.";
  }
  else
  {
    return;
  }
}

LifePointsRegenEndMessage::LifePointsRegenEndMessage()
{
  m_type = MessageEnum::LIFEPOINTSREGENENDMESSAGE;
}

