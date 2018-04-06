#include "LifePointsRegenBeginMessage.h"

void LifePointsRegenBeginMessage::serialize(Writer *param1)
{
  this->serializeAs_LifePointsRegenBeginMessage(param1);
}

void LifePointsRegenBeginMessage::serializeAs_LifePointsRegenBeginMessage(Writer *param1)
{
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - LifePointsRegenBeginMessage -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
  }
  else
  {
    param1->writeByte(this->regenRate);
    return;
  }
}

void LifePointsRegenBeginMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LifePointsRegenBeginMessage(param1);
}

void LifePointsRegenBeginMessage::deserializeAs_LifePointsRegenBeginMessage(Reader *param1)
{
  this->regenRate = param1->readUByte();
  if(this->regenRate < 0 || this->regenRate > 255)
  {
    qDebug()<<"ERREUR - LifePointsRegenBeginMessage -"<<"Forbidden value (" << this->regenRate << ") on element of LifePointsRegenBeginMessage.regenRate.";
  }
  else
  {
    return;
  }
}

LifePointsRegenBeginMessage::LifePointsRegenBeginMessage()
{
  m_type = MessageEnum::LIFEPOINTSREGENBEGINMESSAGE;
}

