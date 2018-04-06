#include "SelectedServerDataExtendedMessage.h"

void SelectedServerDataExtendedMessage::serialize(Writer *param1)
{
  this->serializeAs_SelectedServerDataExtendedMessage(param1);
}

void SelectedServerDataExtendedMessage::serializeAs_SelectedServerDataExtendedMessage(Writer *param1)
{
  SelectedServerDataMessage::serializeAs_SelectedServerDataMessage(param1);
  param1->writeShort((short)this->serverIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->serverIds.size())
  {
    if(this->serverIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - SelectedServerDataExtendedMessage -"<<"Forbidden value (" << this->serverIds[_loc2_] << ") on element 1 (starting at 1) of serverIds.";
    }
    else
    {
      param1->writeVarShort((int)this->serverIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void SelectedServerDataExtendedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SelectedServerDataExtendedMessage(param1);
}

void SelectedServerDataExtendedMessage::deserializeAs_SelectedServerDataExtendedMessage(Reader *param1)
{
  uint _loc4_ = 0;
  SelectedServerDataMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhShort();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - SelectedServerDataExtendedMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of serverIds.";
    }
    else
    {
      this->serverIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

SelectedServerDataExtendedMessage::SelectedServerDataExtendedMessage()
{
  m_type = MessageEnum::SELECTEDSERVERDATAEXTENDEDMESSAGE;
}

