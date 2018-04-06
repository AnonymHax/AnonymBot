#include "ChallengeResultMessage.h"

void ChallengeResultMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeResultMessage(param1);
}

void ChallengeResultMessage::serializeAs_ChallengeResultMessage(Writer *param1)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeResultMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  else
  {
    param1->writeVarShort((int)this->challengeId);
    param1->writeBool(this->success);
    return;
  }
}

void ChallengeResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeResultMessage(param1);
}

void ChallengeResultMessage::deserializeAs_ChallengeResultMessage(Reader *param1)
{
  this->challengeId = param1->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeResultMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeResultMessage.challengeId.";
  }
  else
  {
    this->success = param1->readBool();
    return;
  }
}

ChallengeResultMessage::ChallengeResultMessage()
{
  m_type = MessageEnum::CHALLENGERESULTMESSAGE;
}

