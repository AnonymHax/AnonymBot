#include "QuestStepInfoMessage.h"

void QuestStepInfoMessage::serialize(Writer *param1)
{
  this->serializeAs_QuestStepInfoMessage(param1);
}

void QuestStepInfoMessage::serializeAs_QuestStepInfoMessage(Writer *param1)
{
  param1->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(param1);
}

void QuestStepInfoMessage::deserialize(Reader *param1)
{
  this->deserializeAs_QuestStepInfoMessage(param1);
}

void QuestStepInfoMessage::deserializeAs_QuestStepInfoMessage(Reader *param1)
{
  uint _loc2_ = param1->readUShort();
  this->infos = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->infos->deserialize(param1);
}

QuestStepInfoMessage::QuestStepInfoMessage()
{
  m_type = MessageEnum::QUESTSTEPINFOMESSAGE;
}

