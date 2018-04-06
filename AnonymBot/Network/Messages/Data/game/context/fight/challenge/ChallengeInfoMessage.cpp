#include "ChallengeInfoMessage.h"

void ChallengeInfoMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeInfoMessage(param1);
}

void ChallengeInfoMessage::serializeAs_ChallengeInfoMessage(Writer *param1)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  else
  {
    param1->writeVarShort((int)this->challengeId);
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeDouble(this->targetId);
      if(this->xpBonus < 0)
      {
        qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->xpBonus << ") on element xpBonus.";
      }
      else
      {
        param1->writeVarInt((int)this->xpBonus);
        if(this->dropBonus < 0)
        {
          qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->dropBonus << ") on element dropBonus.";
        }
        else
        {
          param1->writeVarInt((int)this->dropBonus);
          return;
        }
      }
    }
  }
}

void ChallengeInfoMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeInfoMessage(param1);
}

void ChallengeInfoMessage::deserializeAs_ChallengeInfoMessage(Reader *param1)
{
  this->challengeId = param1->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeInfoMessage.challengeId.";
  }
  else
  {
    this->targetId = param1->readDouble();
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->targetId << ") on element of ChallengeInfoMessage.targetId.";
    }
    else
    {
      this->xpBonus = param1->readVarUhInt();
      if(this->xpBonus < 0)
      {
        qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->xpBonus << ") on element of ChallengeInfoMessage.xpBonus.";
      }
      else
      {
        this->dropBonus = param1->readVarUhInt();
        if(this->dropBonus < 0)
        {
          qDebug()<<"ERREUR - ChallengeInfoMessage -"<<"Forbidden value (" << this->dropBonus << ") on element of ChallengeInfoMessage.dropBonus.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

ChallengeInfoMessage::ChallengeInfoMessage()
{
  m_type = MessageEnum::CHALLENGEINFOMESSAGE;
}

