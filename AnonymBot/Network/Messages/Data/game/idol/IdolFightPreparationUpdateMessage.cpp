#include "IdolFightPreparationUpdateMessage.h"

void IdolFightPreparationUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolFightPreparationUpdateMessage(param1);
}

void IdolFightPreparationUpdateMessage::serializeAs_IdolFightPreparationUpdateMessage(Writer *param1)
{
  param1->writeByte(this->idolSource);
  param1->writeShort((short)this->idols.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->idols.size())
  {
    param1->writeShort((short)qSharedPointerCast<Idol>(this->idols[_loc2_])->getTypes().last());
    qSharedPointerCast<Idol>(this->idols[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void IdolFightPreparationUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolFightPreparationUpdateMessage(param1);
}

void IdolFightPreparationUpdateMessage::deserializeAs_IdolFightPreparationUpdateMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<Idol> _loc5_ ;
  this->idolSource = param1->readByte();
  if(this->idolSource < 0)
  {
    qDebug()<<"ERREUR - IdolFightPreparationUpdateMessage -"<<"Forbidden value (" << this->idolSource << ") on element of IdolFightPreparationUpdateMessage.idolSource.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<Idol>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->idols.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

IdolFightPreparationUpdateMessage::IdolFightPreparationUpdateMessage()
{
  m_type = MessageEnum::IDOLFIGHTPREPARATIONUPDATEMESSAGE;
}

