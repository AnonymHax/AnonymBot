#include "AchievementDetailsRequestMessage.h"

void AchievementDetailsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementDetailsRequestMessage(param1);
}

void AchievementDetailsRequestMessage::serializeAs_AchievementDetailsRequestMessage(Writer *param1)
{
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailsRequestMessage -"<<"Forbidden value (" << this->achievementId << ") on element achievementId.";
  }
  else
  {
    param1->writeVarShort((int)this->achievementId);
    return;
  }
}

void AchievementDetailsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementDetailsRequestMessage(param1);
}

void AchievementDetailsRequestMessage::deserializeAs_AchievementDetailsRequestMessage(Reader *param1)
{
  this->achievementId = param1->readVarUhShort();
  if(this->achievementId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailsRequestMessage -"<<"Forbidden value (" << this->achievementId << ") on element of AchievementDetailsRequestMessage.achievementId.";
  }
  else
  {
    return;
  }
}

AchievementDetailsRequestMessage::AchievementDetailsRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILSREQUESTMESSAGE;
}

