#include "QuestStepStartedMessage.h"

void QuestStepStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStepStartedMessage(param1);
}

void QuestStepStartedMessage::serializeAs_QuestStepStartedMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    if(this->stepId < 0)
    {
      qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
    }
    else
    {
      param1->writeVarShort((int)this->stepId);
      return;
    }
  }
}

void QuestStepStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStepStartedMessage(param1);
}

void QuestStepStartedMessage::deserializeAs_QuestStepStartedMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepStartedMessage.questId.";
  }
  else
  {
    this->stepId = param1->readVarUhShort();
    if(this->stepId < 0)
    {
      qDebug()<<"ERREUR - QuestStepStartedMessage -"<<"Forbidden value (" << this->stepId << ") on element of QuestStepStartedMessage.stepId.";
    }
    else
    {
      return;
    }
  }
}

QuestStepStartedMessage::QuestStepStartedMessage()
{
  m_type = MessageEnum::QUESTSTEPSTARTEDMESSAGE;
}

