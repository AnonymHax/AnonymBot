#include "UpdateLifePointsMessage.h"

void UpdateLifePointsMessage::serialize(Writer *param1)
{
  this->serializeAs_UpdateLifePointsMessage(param1);
}

void UpdateLifePointsMessage::serializeAs_UpdateLifePointsMessage(Writer *param1)
{
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  else
  {
    param1->writeVarInt((int)this->lifePoints);
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
    }
    else
    {
      param1->writeVarInt((int)this->maxLifePoints);
      return;
    }
  }
}

void UpdateLifePointsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateLifePointsMessage(param1);
}

void UpdateLifePointsMessage::deserializeAs_UpdateLifePointsMessage(Reader *param1)
{
  this->lifePoints = param1->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->lifePoints << ") on element of UpdateLifePointsMessage.lifePoints.";
  }
  else
  {
    this->maxLifePoints = param1->readVarUhInt();
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - UpdateLifePointsMessage -"<<"Forbidden value (" << this->maxLifePoints << ") on element of UpdateLifePointsMessage.maxLifePoints.";
    }
    else
    {
      return;
    }
  }
}

UpdateLifePointsMessage::UpdateLifePointsMessage()
{
  m_type = MessageEnum::UPDATELIFEPOINTSMESSAGE;
}

