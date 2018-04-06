#include "QuestListMessage.h"

void QuestListMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestListMessage(param1);
}

void QuestListMessage::serializeAs_QuestListMessage(Writer *param1)
{
  param1->writeShort((short)this->finishedQuestsIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->finishedQuestsIds.size())
  {
    if(this->finishedQuestsIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->finishedQuestsIds[_loc2_] << ") on element 1 (starting at 1) of finishedQuestsIds.";
    }
    else
    {
      param1->writeVarShort((int)this->finishedQuestsIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->finishedQuestsCounts.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->finishedQuestsCounts.size())
  {
    if(this->finishedQuestsCounts[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->finishedQuestsCounts[_loc3_] << ") on element 2 (starting at 1) of finishedQuestsCounts.";
    }
    else
    {
      param1->writeVarShort((int)this->finishedQuestsCounts[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeShort((short)this->activeQuests.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->activeQuests.size())
  {
    param1->writeShort((short)qSharedPointerCast<QuestActiveInformations>(this->activeQuests[_loc4_])->getTypes().last());
    qSharedPointerCast<QuestActiveInformations>(this->activeQuests[_loc4_])->serialize(param1);
    _loc4_++;
  }
  param1->writeShort((short)this->reinitDoneQuestsIds.size());
  uint _loc5_ = 0;
  while(_loc5_ < this->reinitDoneQuestsIds.size())
  {
    if(this->reinitDoneQuestsIds[_loc5_] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->reinitDoneQuestsIds[_loc5_] << ") on element 4 (starting at 1) of reinitDoneQuestsIds.";
    }
    else
    {
      param1->writeVarShort((int)this->reinitDoneQuestsIds[_loc5_]);
      _loc5_++;
      continue;
    }
  }
}

void QuestListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestListMessage(param1);
}

void QuestListMessage::deserializeAs_QuestListMessage(Reader *param1)
{
  uint _loc10_ = 0;
  uint _loc11_ = 0;
  uint _loc12_ = 0;
  QSharedPointer<QuestActiveInformations> _loc13_ ;
  uint _loc14_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc10_ = param1->readVarUhShort();
    if(_loc10_ < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _loc10_ << ") on elements of finishedQuestsIds.";
    }
    else
    {
      this->finishedQuestsIds.append(_loc10_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc11_ = param1->readVarUhShort();
    if(_loc11_ < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _loc11_ << ") on elements of finishedQuestsCounts.";
    }
    else
    {
      this->finishedQuestsCounts.append(_loc11_);
      _loc5_++;
      continue;
    }
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc12_ = param1->readUShort();
    _loc13_ = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_loc12_));
    _loc13_->deserialize(param1);
    this->activeQuests.append(_loc13_);
    _loc7_++;
  }
  uint _loc8_ = param1->readUShort();
  uint _loc9_ = 0;
  while(_loc9_ < _loc8_)
  {
    _loc14_ = param1->readVarUhShort();
    if(_loc14_ < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _loc14_ << ") on elements of reinitDoneQuestsIds.";
    }
    else
    {
      this->reinitDoneQuestsIds.append(_loc14_);
      _loc9_++;
      continue;
    }
  }
}

QuestListMessage::QuestListMessage()
{
  m_type = MessageEnum::QUESTLISTMESSAGE;
}

