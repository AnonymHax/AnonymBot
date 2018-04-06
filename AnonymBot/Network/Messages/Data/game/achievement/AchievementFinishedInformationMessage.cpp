#include "AchievementFinishedInformationMessage.h"

void AchievementFinishedInformationMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementFinishedInformationMessage(param1);
}

void AchievementFinishedInformationMessage::serializeAs_AchievementFinishedInformationMessage(Writer *param1)
{
  AchievementFinishedMessage::serializeAs_AchievementFinishedMessage(param1);
  param1->writeUTF(this->name);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AchievementFinishedInformationMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void AchievementFinishedInformationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementFinishedInformationMessage(param1);
}

void AchievementFinishedInformationMessage::deserializeAs_AchievementFinishedInformationMessage(Reader *param1)
{
  AchievementFinishedMessage::deserialize(param1);
  this->name = param1->readUTF();
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AchievementFinishedInformationMessage -"<<"Forbidden value (" << this->playerId << ") on element of AchievementFinishedInformationMessage.playerId.";
  }
  else
  {
    return;
  }
}

AchievementFinishedInformationMessage::AchievementFinishedInformationMessage()
{
  m_type = MessageEnum::ACHIEVEMENTFINISHEDINFORMATIONMESSAGE;
}

