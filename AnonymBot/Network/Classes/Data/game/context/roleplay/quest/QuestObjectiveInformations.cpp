#include "QuestObjectiveInformations.h"

void QuestObjectiveInformations::serialize(Writer *param1)
{
  this->serializeAs_QuestObjectiveInformations(param1);
}

void QuestObjectiveInformations::serializeAs_QuestObjectiveInformations(Writer *param1)
{
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformations -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
  }
  else
  {
    param1->writeVarShort((int)this->objectiveId);
    param1->writeBool(this->objectiveStatus);
    param1->writeShort((short)this->dialogParams.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->dialogParams.size())
    {
      param1->writeUTF(this->dialogParams[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void QuestObjectiveInformations::deserialize(Reader *param1)
{
  this->deserializeAs_QuestObjectiveInformations(param1);
}

void QuestObjectiveInformations::deserializeAs_QuestObjectiveInformations(Reader *param1)
{
  QString _loc4_ ;
  this->objectiveId = param1->readVarUhShort();
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformations -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveInformations.objectiveId.";
  }
  else
  {
    this->objectiveStatus = param1->readBool();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUTF();
      this->dialogParams.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

QuestObjectiveInformations::QuestObjectiveInformations()
{
  m_types<<ClassEnum::QUESTOBJECTIVEINFORMATIONS;
}

bool QuestObjectiveInformations::operator==(const QuestObjectiveInformations &compared)
{
  if(objectiveId == compared.objectiveId)
  if(objectiveStatus == compared.objectiveStatus)
  if(dialogParams == compared.dialogParams)
  return true;
  
  return false;
}

