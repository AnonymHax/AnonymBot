#include "QuestStepValidatedMessage.h"

void QuestStepValidatedMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStepValidatedMessage(param1);
}

void QuestStepValidatedMessage::serializeAs_QuestStepValidatedMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    if(this->stepId < 0)
    {
      qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
    }
    else
    {
      param1->writeVarShort((int)this->stepId);
      return;
    }
  }
}

void QuestStepValidatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStepValidatedMessage(param1);
}

void QuestStepValidatedMessage::deserializeAs_QuestStepValidatedMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestStepValidatedMessage.questId.";
  }
  else
  {
    this->stepId = param1->readVarUhShort();
    if(this->stepId < 0)
    {
      qDebug()<<"ERREUR - QuestStepValidatedMessage -"<<"Forbidden value (" << this->stepId << ") on element of QuestStepValidatedMessage.stepId.";
    }
    else
    {
      return;
    }
  }
}

QuestStepValidatedMessage::QuestStepValidatedMessage()
{
  m_type = MessageEnum::QUESTSTEPVALIDATEDMESSAGE;
}

