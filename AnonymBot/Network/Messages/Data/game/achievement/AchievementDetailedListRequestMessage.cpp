#include "AchievementDetailedListRequestMessage.h"

void AchievementDetailedListRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementDetailedListRequestMessage(param1);
}

void AchievementDetailedListRequestMessage::serializeAs_AchievementDetailedListRequestMessage(Writer *param1)
{
  if(this->categoryId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailedListRequestMessage -"<<"Forbidden value (" << this->categoryId << ") on element categoryId.";
  }
  else
  {
    param1->writeVarShort((int)this->categoryId);
    return;
  }
}

void AchievementDetailedListRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementDetailedListRequestMessage(param1);
}

void AchievementDetailedListRequestMessage::deserializeAs_AchievementDetailedListRequestMessage(Reader *param1)
{
  this->categoryId = param1->readVarUhShort();
  if(this->categoryId < 0)
  {
    qDebug()<<"ERREUR - AchievementDetailedListRequestMessage -"<<"Forbidden value (" << this->categoryId << ") on element of AchievementDetailedListRequestMessage.categoryId.";
  }
  else
  {
    return;
  }
}

AchievementDetailedListRequestMessage::AchievementDetailedListRequestMessage()
{
  m_type = MessageEnum::ACHIEVEMENTDETAILEDLISTREQUESTMESSAGE;
}

