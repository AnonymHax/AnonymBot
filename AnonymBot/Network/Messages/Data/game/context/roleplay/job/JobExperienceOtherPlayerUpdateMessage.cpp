#include "JobExperienceOtherPlayerUpdateMessage.h"

void JobExperienceOtherPlayerUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_JobExperienceOtherPlayerUpdateMessage(param1);
}

void JobExperienceOtherPlayerUpdateMessage::serializeAs_JobExperienceOtherPlayerUpdateMessage(Writer *param1)
{
  JobExperienceUpdateMessage::serializeAs_JobExperienceUpdateMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperienceOtherPlayerUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void JobExperienceOtherPlayerUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobExperienceOtherPlayerUpdateMessage(param1);
}

void JobExperienceOtherPlayerUpdateMessage::deserializeAs_JobExperienceOtherPlayerUpdateMessage(Reader *param1)
{
  JobExperienceUpdateMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobExperienceOtherPlayerUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobExperienceOtherPlayerUpdateMessage.playerId.";
  }
  else
  {
    return;
  }
}

JobExperienceOtherPlayerUpdateMessage::JobExperienceOtherPlayerUpdateMessage()
{
  m_type = MessageEnum::JOBEXPERIENCEOTHERPLAYERUPDATEMESSAGE;
}

