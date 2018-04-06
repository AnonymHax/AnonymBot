#include "SetUpdateMessage.h"

void SetUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_SetUpdateMessage(param1);
}

void SetUpdateMessage::serializeAs_SetUpdateMessage(Writer *param1)
{
  if(this->setId < 0)
  {
    qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setId << ") on element setId.";
  }
  else
  {
    param1->writeVarShort((int)this->setId);
    param1->writeShort((short)this->setObjects.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->setObjects.size())
    {
      if(this->setObjects[_loc2_] < 0)
      {
        qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setObjects[_loc2_] << ") on element 2 (starting at 1) of setObjects.";
      }
      else
      {
        param1->writeVarShort((int)this->setObjects[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    param1->writeShort((short)this->setEffects.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->setEffects.size())
    {
      param1->writeShort((short)qSharedPointerCast<ObjectEffect>(this->setEffects[_loc3_])->getTypes().last());
      qSharedPointerCast<ObjectEffect>(this->setEffects[_loc3_])->serialize(param1);
      _loc3_++;
    }
    return;
  }
}

void SetUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SetUpdateMessage(param1);
}

void SetUpdateMessage::deserializeAs_SetUpdateMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  QSharedPointer<ObjectEffect> _loc8_ ;
  this->setId = param1->readVarUhShort();
  if(this->setId < 0)
  {
    qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << this->setId << ") on element of SetUpdateMessage.setId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readVarUhShort();
      if(_loc6_ < 0)
      {
        qDebug()<<"ERREUR - SetUpdateMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of setObjects.";
      }
      else
      {
        this->setObjects.append(_loc6_);
        _loc3_++;
        continue;
      }
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc7_ = param1->readUShort();
      _loc8_ = qSharedPointerCast<ObjectEffect>(ClassManagerSingleton::get()->getClass(_loc7_));
      _loc8_->deserialize(param1);
      this->setEffects.append(_loc8_);
      _loc5_++;
    }
    return;
  }
}

SetUpdateMessage::SetUpdateMessage()
{
  m_type = MessageEnum::SETUPDATEMESSAGE;
}

