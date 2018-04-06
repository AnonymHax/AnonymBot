#include "SlaveSwitchContextMessage.h"

void SlaveSwitchContextMessage::serialize(Writer *param1)
{
  this->serializeAs_SlaveSwitchContextMessage(param1);
}

void SlaveSwitchContextMessage::serializeAs_SlaveSwitchContextMessage(Writer *param1)
{
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->masterId << ") on element masterId.";
  }
  else
  {
    param1->writeDouble(this->masterId);
    if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveId << ") on element slaveId.";
    }
    else
    {
      param1->writeDouble(this->slaveId);
      param1->writeShort((short)this->slaveSpells.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->slaveSpells.size())
      {
        (this->slaveSpells[_loc2_]).serializeAs_SpellItem(param1);
        _loc2_++;
      }
      this->slaveStats.serializeAs_CharacterCharacteristicsInformations(param1);
      param1->writeShort((short)this->shortcuts.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->shortcuts.size())
      {
        param1->writeShort((short)qSharedPointerCast<Shortcut>(this->shortcuts[_loc3_])->getTypes().last());
        qSharedPointerCast<Shortcut>(this->shortcuts[_loc3_])->serialize(param1);
        _loc3_++;
      }
      return;
    }
  }
}

void SlaveSwitchContextMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SlaveSwitchContextMessage(param1);
}

void SlaveSwitchContextMessage::deserializeAs_SlaveSwitchContextMessage(Reader *param1)
{
  SpellItem _loc6_ ;
  uint _loc7_ = 0;
  QSharedPointer<Shortcut> _loc8_ ;
  this->masterId = param1->readDouble();
  if(this->masterId < -9.007199254740992E15 || this->masterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->masterId << ") on element of SlaveSwitchContextMessage.masterId.";
  }
  else
  {
    this->slaveId = param1->readDouble();
    if(this->slaveId < -9.007199254740992E15 || this->slaveId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SlaveSwitchContextMessage -"<<"Forbidden value (" << this->slaveId << ") on element of SlaveSwitchContextMessage.slaveId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc6_ = SpellItem();
        _loc6_.deserialize(param1);
        this->slaveSpells.append(_loc6_);
        _loc3_++;
      }
      this->slaveStats = CharacterCharacteristicsInformations();
      this->slaveStats.deserialize(param1);
      uint _loc4_ = param1->readUShort();
      uint _loc5_ = 0;
      while(_loc5_ < _loc4_)
      {
        _loc7_ = param1->readUShort();
        _loc8_ = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_loc7_));
        _loc8_->deserialize(param1);
        this->shortcuts.append(_loc8_);
        _loc5_++;
      }
      return;
    }
  }
}

SlaveSwitchContextMessage::SlaveSwitchContextMessage()
{
  m_type = MessageEnum::SLAVESWITCHCONTEXTMESSAGE;
}

