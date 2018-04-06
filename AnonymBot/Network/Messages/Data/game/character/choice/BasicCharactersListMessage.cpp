#include "BasicCharactersListMessage.h"

void BasicCharactersListMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicCharactersListMessage(param1);
}

void BasicCharactersListMessage::serializeAs_BasicCharactersListMessage(Writer *param1)
{
  param1->writeShort((short)this->characters.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->characters.size())
  {
    param1->writeShort((short)qSharedPointerCast<CharacterBaseInformations>(this->characters[_loc2_])->getTypes().last());
    qSharedPointerCast<CharacterBaseInformations>(this->characters[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void BasicCharactersListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicCharactersListMessage(param1);
}

void BasicCharactersListMessage::deserializeAs_BasicCharactersListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<CharacterBaseInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<CharacterBaseInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->characters.append(_loc5_);
    _loc3_++;
  }
}

BasicCharactersListMessage::BasicCharactersListMessage()
{
  m_type = MessageEnum::BASICCHARACTERSLISTMESSAGE;
}

