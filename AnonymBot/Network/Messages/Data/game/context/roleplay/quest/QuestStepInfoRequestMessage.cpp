#include "QuestStepInfoRequestMessage.h"

void QuestStepInfoRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStepInfoRequestMessage(param1);
}

void QuestStepInfoRequestMessage::serializeAs_QuestStepInfoRequestMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepInfoRequestMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    return;
  }
}

void QuestStepInfoRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStepInfoRequestMessage(param1);
}

void QuestStepInfoRequestMessage::deserializeAs_QuestStepInfoRequestMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepInfoRequestMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepInfoRequestMessage.questId.";
  }
  else
  {
    return;
  }
}

QuestStepInfoRequestMessage::QuestStepInfoRequestMessage()
{
  m_type = MessageEnum::QUESTSTEPINFOREQUESTMESSAGE;
}

