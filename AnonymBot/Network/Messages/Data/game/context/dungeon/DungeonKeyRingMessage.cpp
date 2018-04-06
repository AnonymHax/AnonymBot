#include "DungeonKeyRingMessage.h"

void DungeonKeyRingMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonKeyRingMessage(param1);
}

void DungeonKeyRingMessage::serializeAs_DungeonKeyRingMessage(Writer *param1)
{
  param1->writeShort((short)this->availables.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->availables.size())
  {
    if(this->availables[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << this->availables[_loc2_] << ") on element 1 (starting at 1) of availables.";
    }
    else
    {
      param1->writeVarShort((int)this->availables[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->unavailables.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->unavailables.size())
  {
    if(this->unavailables[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << this->unavailables[_loc3_] << ") on element 2 (starting at 1) of unavailables.";
    }
    else
    {
      param1->writeVarShort((int)this->unavailables[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void DungeonKeyRingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonKeyRingMessage(param1);
}

void DungeonKeyRingMessage::deserializeAs_DungeonKeyRingMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of availables.";
    }
    else
    {
      this->availables.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readVarUhShort();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - DungeonKeyRingMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of unavailables.";
    }
    else
    {
      this->unavailables.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

DungeonKeyRingMessage::DungeonKeyRingMessage()
{
  m_type = MessageEnum::DUNGEONKEYRINGMESSAGE;
}

