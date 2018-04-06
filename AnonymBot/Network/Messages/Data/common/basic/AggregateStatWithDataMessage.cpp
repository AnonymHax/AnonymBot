#include "AggregateStatWithDataMessage.h"

void AggregateStatWithDataMessage::serialize(Writer *param1)
{
  this->serializeAs_AggregateStatWithDataMessage(param1);
}

void AggregateStatWithDataMessage::serializeAs_AggregateStatWithDataMessage(Writer *param1)
{
  AggregateStatMessage::serializeAs_AggregateStatMessage(param1);
  param1->writeShort((short)this->datas.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->datas.size())
  {
    param1->writeShort((short)qSharedPointerCast<StatisticData>(this->datas[_loc2_])->getTypes().last());
    qSharedPointerCast<StatisticData>(this->datas[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void AggregateStatWithDataMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AggregateStatWithDataMessage(param1);
}

void AggregateStatWithDataMessage::deserializeAs_AggregateStatWithDataMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<StatisticData> _loc5_ ;
  AggregateStatMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<StatisticData>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->datas.append(_loc5_);
    _loc3_++;
  }
}

AggregateStatWithDataMessage::AggregateStatWithDataMessage()
{
  m_type = MessageEnum::AGGREGATESTATWITHDATAMESSAGE;
}

