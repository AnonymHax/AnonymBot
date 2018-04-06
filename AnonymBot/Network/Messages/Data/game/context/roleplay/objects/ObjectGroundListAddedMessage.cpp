#include "ObjectGroundListAddedMessage.h"

void ObjectGroundListAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectGroundListAddedMessage(param1);
}

void ObjectGroundListAddedMessage::serializeAs_ObjectGroundListAddedMessage(Writer *param1)
{
  param1->writeShort((short)this->cells.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->cells.size())
  {
    if(this->cells[_loc2_] < 0 || this->cells[_loc2_] > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << this->cells[_loc2_] << ") on element 1 (starting at 1) of cells.";
    }
    else
    {
      param1->writeVarShort((int)this->cells[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->referenceIds.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->referenceIds.size())
  {
    if(this->referenceIds[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << this->referenceIds[_loc3_] << ") on element 2 (starting at 1) of referenceIds.";
    }
    else
    {
      param1->writeVarShort((int)this->referenceIds[_loc3_]);
      _loc3_++;
      continue;
    }
  }
}

void ObjectGroundListAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectGroundListAddedMessage(param1);
}

void ObjectGroundListAddedMessage::deserializeAs_ObjectGroundListAddedMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0 || _loc6_ > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of cells.";
    }
    else
    {
      this->cells.append(_loc6_);
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
      qDebug()<<"ERREUR - ObjectGroundListAddedMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of referenceIds.";
    }
    else
    {
      this->referenceIds.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

ObjectGroundListAddedMessage::ObjectGroundListAddedMessage()
{
  m_type = MessageEnum::OBJECTGROUNDLISTADDEDMESSAGE;
}

