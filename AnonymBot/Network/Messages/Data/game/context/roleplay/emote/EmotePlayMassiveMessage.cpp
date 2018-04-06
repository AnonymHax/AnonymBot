#include "EmotePlayMassiveMessage.h"

void EmotePlayMassiveMessage::serialize(Writer *param1)
{
  this->serializeAs_EmotePlayMassiveMessage(param1);
}

void EmotePlayMassiveMessage::serializeAs_EmotePlayMassiveMessage(Writer *param1)
{
  EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(param1);
  param1->writeShort((short)this->actorIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->actorIds.size())
  {
    if(this->actorIds[_loc2_] < -9.007199254740992E15 || this->actorIds[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - EmotePlayMassiveMessage -"<<"Forbidden value (" << this->actorIds[_loc2_] << ") on element 1 (starting at 1) of actorIds.";
    }
    else
    {
      param1->writeDouble(this->actorIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void EmotePlayMassiveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmotePlayMassiveMessage(param1);
}

void EmotePlayMassiveMessage::deserializeAs_EmotePlayMassiveMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  EmotePlayAbstractMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readDouble();
    if(_loc4_ < -9.007199254740992E15 || _loc4_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - EmotePlayMassiveMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of actorIds.";
    }
    else
    {
      this->actorIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

EmotePlayMassiveMessage::EmotePlayMassiveMessage()
{
  m_type = MessageEnum::EMOTEPLAYMASSIVEMESSAGE;
}

