#include "QuestActiveInformations.h"

void QuestActiveInformations::serialize(Writer *param1)
{
  this->serializeAs_QuestActiveInformations(param1);
}

void QuestActiveInformations::serializeAs_QuestActiveInformations(Writer *param1)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveInformations -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  else
  {
    param1->writeVarShort((int)this->questId);
    return;
  }
}

void QuestActiveInformations::deserialize(Reader *param1)
{
  this->deserializeAs_QuestActiveInformations(param1);
}

void QuestActiveInformations::deserializeAs_QuestActiveInformations(Reader *param1)
{
  this->questId = param1->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveInformations -"<<"Forbidden value (" << this->questId << ") on element of QuestActiveInformations.questId.";
  }
  else
  {
    return;
  }
}

QuestActiveInformations::QuestActiveInformations()
{
  m_types<<ClassEnum::QUESTACTIVEINFORMATIONS;
}

bool QuestActiveInformations::operator==(const QuestActiveInformations &compared)
{
  if(questId == compared.questId)
  return true;
  
  return false;
}

