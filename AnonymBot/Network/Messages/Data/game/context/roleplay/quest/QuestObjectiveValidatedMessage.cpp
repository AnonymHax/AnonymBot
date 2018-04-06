#include "QuestObjectiveValidatedMessage.h"

void QuestObjectiveValidatedMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestObjectiveValidatedMessage(param1);
}

void QuestObjectiveValidatedMessage::serializeAs_QuestObjectiveValidatedMessage(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    if(this->objectiveId < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
    }
    else
    {
      param1->writeVarShort((int)this->objectiveId);
      return;
    }
  }
}

void QuestObjectiveValidatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestObjectiveValidatedMessage(param1);
}

void QuestObjectiveValidatedMessage::deserializeAs_QuestObjectiveValidatedMessage(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->questId << ") on element of QuestObjectiveValidatedMessage.questId.";
  }
  else
  {
    this->objectiveId = param1->readVarUhShort();
    if(this->objectiveId < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveValidatedMessage -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveValidatedMessage.objectiveId.";
    }
    else
    {
      return;
    }
  }
}

QuestObjectiveValidatedMessage::QuestObjectiveValidatedMessage()
{
  m_type = MessageEnum::QUESTOBJECTIVEVALIDATEDMESSAGE;
}

