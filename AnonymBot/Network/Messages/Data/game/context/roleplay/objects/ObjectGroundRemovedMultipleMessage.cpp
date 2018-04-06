#include "ObjectGroundRemovedMultipleMessage.h"

void ObjectGroundRemovedMultipleMessage::serialize(Writer *param1)
{
  this->serializeAs_ObjectGroundRemovedMultipleMessage(param1);
}

void ObjectGroundRemovedMultipleMessage::serializeAs_ObjectGroundRemovedMultipleMessage(Writer *param1)
{
  param1->writeShort((short)this->cells.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->cells.size())
  {
    if(this->cells[_loc2_] < 0 || this->cells[_loc2_] > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundRemovedMultipleMessage -"<<"Forbidden value (" << this->cells[_loc2_] << ") on element 1 (starting at 1) of cells.";
    }
    else
    {
      param1->writeVarShort((int)this->cells[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ObjectGroundRemovedMultipleMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectGroundRemovedMultipleMessage(param1);
}

void ObjectGroundRemovedMultipleMessage::deserializeAs_ObjectGroundRemovedMultipleMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0 || _loc4_ > 559)
    {
      qDebug()<<"ERREUR - ObjectGroundRemovedMultipleMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of cells.";
    }
    else
    {
      this->cells.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ObjectGroundRemovedMultipleMessage::ObjectGroundRemovedMultipleMessage()
{
  m_type = MessageEnum::OBJECTGROUNDREMOVEDMULTIPLEMESSAGE;
}

