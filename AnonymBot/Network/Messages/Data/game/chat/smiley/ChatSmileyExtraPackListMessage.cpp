#include "ChatSmileyExtraPackListMessage.h"

void ChatSmileyExtraPackListMessage::serialize(Writer *param1)
{
  this->serializeAs_ChatSmileyExtraPackListMessage(param1);
}

void ChatSmileyExtraPackListMessage::serializeAs_ChatSmileyExtraPackListMessage(Writer *param1)
{
  param1->writeShort((short)this->packIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->packIds.size())
  {
    if(this->packIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyExtraPackListMessage -"<<"Forbidden value (" << this->packIds[_loc2_] << ") on element 1 (starting at 1) of packIds.";
    }
    else
    {
      param1->writeByte(this->packIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void ChatSmileyExtraPackListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChatSmileyExtraPackListMessage(param1);
}

void ChatSmileyExtraPackListMessage::deserializeAs_ChatSmileyExtraPackListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readByte();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - ChatSmileyExtraPackListMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of packIds.";
    }
    else
    {
      this->packIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

ChatSmileyExtraPackListMessage::ChatSmileyExtraPackListMessage()
{
  m_type = MessageEnum::CHATSMILEYEXTRAPACKLISTMESSAGE;
}

