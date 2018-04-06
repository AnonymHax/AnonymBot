#include "AchievementFinishedMessage.h"

void AchievementFinishedMessage::serialize(Writer *param1)
{
  this->serializeAs_AchievementFinishedMessage(param1);
}

void AchievementFinishedMessage::serializeAs_AchievementFinishedMessage(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementFinishedMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    if(this->finishedlevel < 0 || this->finishedlevel > 206)
    {
      qDebug()<<"ERREUR - AchievementFinishedMessage -"<<"Forbidden value (" << this->finishedlevel << ") on element finishedlevel.";
    }
    else
    {
      param1->writeByte(this->finishedlevel);
      return;
    }
  }
}

void AchievementFinishedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AchievementFinishedMessage(param1);
}

void AchievementFinishedMessage::deserializeAs_AchievementFinishedMessage(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - AchievementFinishedMessage -"<<"Forbidden value (" << this->id << ") on element of AchievementFinishedMessage.id.";
  }
  else
  {
    this->finishedlevel = param1->readUByte();
    if(this->finishedlevel < 0 || this->finishedlevel > 206)
    {
      qDebug()<<"ERREUR - AchievementFinishedMessage -"<<"Forbidden value (" << this->finishedlevel << ") on element of AchievementFinishedMessage.finishedlevel.";
    }
    else
    {
      return;
    }
  }
}

AchievementFinishedMessage::AchievementFinishedMessage()
{
  m_type = MessageEnum::ACHIEVEMENTFINISHEDMESSAGE;
}

