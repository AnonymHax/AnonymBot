#include "QuestObjectiveInformationsWithCompletion.h"

void QuestObjectiveInformationsWithCompletion::serialize(Writer *param1)
{
  this->serializeAs_QuestObjectiveInformationsWithCompletion(param1);
}

void QuestObjectiveInformationsWithCompletion::serializeAs_QuestObjectiveInformationsWithCompletion(Writer *param1)
{
  QuestObjectiveInformations::serializeAs_QuestObjectiveInformations(param1);
  if(this->curCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->curCompletion << ") on element curCompletion.";
  }
  else
  {
    param1->writeVarShort((int)this->curCompletion);
    if(this->maxCompletion < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->maxCompletion << ") on element maxCompletion.";
    }
    else
    {
      param1->writeVarShort((int)this->maxCompletion);
      return;
    }
  }
}

void QuestObjectiveInformationsWithCompletion::deserialize(Reader *param1)
{
  this->deserializeAs_QuestObjectiveInformationsWithCompletion(param1);
}

void QuestObjectiveInformationsWithCompletion::deserializeAs_QuestObjectiveInformationsWithCompletion(Reader *param1)
{
  QuestObjectiveInformations::deserialize(param1);
  this->curCompletion = param1->readVarUhShort();
  if(this->curCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->curCompletion << ") on element of QuestObjectiveInformationsWithCompletion.curCompletion.";
  }
  else
  {
    this->maxCompletion = param1->readVarUhShort();
    if(this->maxCompletion < 0)
    {
      qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->maxCompletion << ") on element of QuestObjectiveInformationsWithCompletion.maxCompletion.";
    }
    else
    {
      return;
    }
  }
}

QuestObjectiveInformationsWithCompletion::QuestObjectiveInformationsWithCompletion()
{
  m_types<<ClassEnum::QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION;
}

bool QuestObjectiveInformationsWithCompletion::operator==(const QuestObjectiveInformationsWithCompletion &compared)
{
  if(curCompletion == compared.curCompletion)
  if(maxCompletion == compared.maxCompletion)
  return true;
  
  return false;
}

