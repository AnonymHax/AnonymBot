#include "QuestActiveDetailedInformations.h"

void QuestActiveDetailedInformations::serialize(Writer *param1)
{
  this->serializeAs_QuestActiveDetailedInformations(param1);
}

void QuestActiveDetailedInformations::serializeAs_QuestActiveDetailedInformations(Writer *param1)
{
  QuestActiveInformations::serializeAs_QuestActiveInformations(param1);
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveDetailedInformations -"<<"Forbidden value (" << this->stepId << ") on element stepId.";
  }
  else
  {
    param1->writeVarShort((int)this->stepId);
    param1->writeShort((short)this->objectives.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->objectives.size())
    {
      param1->writeShort((short)qSharedPointerCast<QuestObjectiveInformations>(this->objectives[_loc2_])->getTypes().last());
      qSharedPointerCast<QuestObjectiveInformations>(this->objectives[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void QuestActiveDetailedInformations::deserialize(Reader *param1)
{
  this->deserializeAs_QuestActiveDetailedInformations(param1);
}

void QuestActiveDetailedInformations::deserializeAs_QuestActiveDetailedInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<QuestObjectiveInformations> _loc5_ ;
  QuestActiveInformations::deserialize(param1);
  this->stepId = param1->readVarUhShort();
  if(this->stepId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveDetailedInformations -"<<"Forbidden value (" << this->stepId << ") on element of QuestActiveDetailedInformations.stepId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<QuestObjectiveInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->objectives.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

QuestActiveDetailedInformations::QuestActiveDetailedInformations()
{
  m_types<<ClassEnum::QUESTACTIVEDETAILEDINFORMATIONS;
}

bool QuestActiveDetailedInformations::operator==(const QuestActiveDetailedInformations &compared)
{
  if(stepId == compared.stepId)
  if(objectives == compared.objectives)
  return true;
  
  return false;
}

