#include "ChallengeTargetsListRequestMessage.h"

void ChallengeTargetsListRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ChallengeTargetsListRequestMessage(param1);
}

void ChallengeTargetsListRequestMessage::serializeAs_ChallengeTargetsListRequestMessage(Writer *param1)
{
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element challengeId.";
  }
  else
  {
    param1->writeVarShort((int)this->challengeId);
    return;
  }
}

void ChallengeTargetsListRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChallengeTargetsListRequestMessage(param1);
}

void ChallengeTargetsListRequestMessage::deserializeAs_ChallengeTargetsListRequestMessage(Reader *param1)
{
  this->challengeId = param1->readVarUhShort();
  if(this->challengeId < 0)
  {
    qDebug()<<"ERREUR - ChallengeTargetsListRequestMessage -"<<"Forbidden value (" << this->challengeId << ") on element of ChallengeTargetsListRequestMessage.challengeId.";
  }
  else
  {
    return;
  }
}

ChallengeTargetsListRequestMessage::ChallengeTargetsListRequestMessage()
{
  m_type = MessageEnum::CHALLENGETARGETSLISTREQUESTMESSAGE;
}

