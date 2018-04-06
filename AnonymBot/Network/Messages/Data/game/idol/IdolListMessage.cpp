#include "IdolListMessage.h"

void IdolListMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolListMessage(param1);
}

void IdolListMessage::serializeAs_IdolListMessage(Writer *param1)
{
  param1->writeShort((short)this->chosenIdols.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->chosenIdols.size())
  {
    if(this->chosenIdols[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << this->chosenIdols[_loc2_] << ") on element 1 (starting at 1) of chosenIdols.";
    }
    else
    {
      param1->writeVarShort((int)this->chosenIdols[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->partyChosenIdols.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->partyChosenIdols.size())
  {
    if(this->partyChosenIdols[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << this->partyChosenIdols[_loc3_] << ") on element 2 (starting at 1) of partyChosenIdols.";
    }
    else
    {
      param1->writeVarShort((int)this->partyChosenIdols[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeShort((short)this->partyIdols.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->partyIdols.size())
  {
    param1->writeShort((short)qSharedPointerCast<PartyIdol>(this->partyIdols[_loc4_])->getTypes().last());
    qSharedPointerCast<PartyIdol>(this->partyIdols[_loc4_])->serialize(param1);
    _loc4_++;
  }
}

void IdolListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolListMessage(param1);
}

void IdolListMessage::deserializeAs_IdolListMessage(Reader *param1)
{
  uint _loc8_ = 0;
  uint _loc9_ = 0;
  uint _loc10_ = 0;
  QSharedPointer<PartyIdol> _loc11_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc8_ = param1->readVarUhShort();
    if(_loc8_ < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _loc8_ << ") on elements of chosenIdols.";
    }
    else
    {
      this->chosenIdols.append(_loc8_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc9_ = param1->readVarUhShort();
    if(_loc9_ < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _loc9_ << ") on elements of partyChosenIdols.";
    }
    else
    {
      this->partyChosenIdols.append(_loc9_);
      _loc5_++;
      continue;
    }
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc10_ = param1->readUShort();
    _loc11_ = qSharedPointerCast<PartyIdol>(ClassManagerSingleton::get()->getClass(_loc10_));
    _loc11_->deserialize(param1);
    this->partyIdols.append(_loc11_);
    _loc7_++;
  }
}

IdolListMessage::IdolListMessage()
{
  m_type = MessageEnum::IDOLLISTMESSAGE;
}

