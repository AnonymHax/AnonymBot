#include "QuestObjectiveValidationMessage.h"

void QuestObjectiveValidationMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestObjectiveValidationMessage(param1);
}

void QuestObjectiveValidationMessage::serializeAs_QuestObjectiveValidationMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    if(this->objectiveId < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
    }
    else
    {
      param1->writeVarShort((int)this->objectiveId);
      return;
    }
  }
}

void QuestObjectiveValidationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestObjectiveValidationMessage(param1);
}

void QuestObjectiveValidationMessage::deserializeAs_QuestObjectiveValidationMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestObjectiveValidationMessage.questId.";
  }
  else
  {
    this->objectiveId = param1->readVarUhShort();
    if(this->objectiveId < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveValidationMessage -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveValidationMessage.objectiveId.";
    }
    else
    {
      return;
    }
  }
}

QuestObjectiveValidationMessage::QuestObjectiveValidationMessage()
{
  m_type = MessageEnum::QUESTOBJECTIVEVALIDATIONMESSAGE;
}

