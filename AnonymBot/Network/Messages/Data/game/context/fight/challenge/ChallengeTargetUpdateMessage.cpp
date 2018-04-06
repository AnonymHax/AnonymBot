#include "ChallengeTargetUpdateMessage.h"

void ChallengeTargetUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeTargetUpdateMessage(param1);
}

void ChallengeTargetUpdateMessage::serializeAs_ChallengeTargetUpdateMessage(Writer *param1)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  else
  {
    param1->writeVarShort((int)this->challengeId);
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeDouble(this->targetId);
      return;
    }
  }
}

void ChallengeTargetUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeTargetUpdateMessage(param1);
}

void ChallengeTargetUpdateMessage::deserializeAs_ChallengeTargetUpdateMessage(Reader *param1)
{
  this->challengeId = param1->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeTargetUpdateMessage.challengeId.";
  }
  else
  {
    this->targetId = param1->readDouble();
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeTargetUpdateMessage -"<<"Forbidden value (" << this->targetId << ") on element of ChallengeTargetUpdateMessage.targetId.";
    }
    else
    {
      return;
    }
  }
}

ChallengeTargetUpdateMessage::ChallengeTargetUpdateMessage()
{
  m_type = MessageEnum::CHALLENGETARGETUPDATEMESSAGE;
}

