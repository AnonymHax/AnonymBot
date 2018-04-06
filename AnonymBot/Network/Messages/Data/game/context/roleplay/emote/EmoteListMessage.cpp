#include "EmoteListMessage.h"

void EmoteListMessage::serialize(Writer *param1)
{
  this->serializeAs_EmoteListMessage(param1);
}

void EmoteListMessage::serializeAs_EmoteListMessage(Writer *param1)
{
  param1->writeShort((short)this->emoteIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->emoteIds.size())
  {
    if(this->emoteIds[_loc2_] < 0 || this->emoteIds[_loc2_] > 255)
    {
      qDebug()<<"ERREUR - EmoteListMessage -"<<"Forbidden value (" << this->emoteIds[_loc2_] << ") on element 1 (starting at 1) of emoteIds.";
    }
    else
    {
      param1->writeByte(this->emoteIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void EmoteListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmoteListMessage(param1);
}

void EmoteListMessage::deserializeAs_EmoteListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUByte();
    if(_loc4_ < 0 || _loc4_ > 255)
    {
      qDebug()<<"ERREUR - EmoteListMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of emoteIds.";
    }
    else
    {
      this->emoteIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

EmoteListMessage::EmoteListMessage()
{
  m_type = MessageEnum::EMOTELISTMESSAGE;
}

