#include "CharactersListWithRemodelingMessage.h"

void CharactersListWithRemodelingMessage::serialize(Writer *param1)
{
  this->serializeAs_CharactersListWithRemodelingMessage(param1);
}

void CharactersListWithRemodelingMessage::serializeAs_CharactersListWithRemodelingMessage(Writer *param1)
{
  CharactersListMessage::serializeAs_CharactersListMessage(param1);
  param1->writeShort((short)this->charactersToRemodel.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->charactersToRemodel.size())
  {
    (this->charactersToRemodel[_loc2_]).serializeAs_CharacterToRemodelInformations(param1);
    _loc2_++;
  }
}

void CharactersListWithRemodelingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharactersListWithRemodelingMessage(param1);
}

void CharactersListWithRemodelingMessage::deserializeAs_CharactersListWithRemodelingMessage(Reader *param1)
{
  CharacterToRemodelInformations _loc4_ ;
  CharactersListMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = CharacterToRemodelInformations();
    _loc4_.deserialize(param1);
    this->charactersToRemodel.append(_loc4_);
    _loc3_++;
  }
}

CharactersListWithRemodelingMessage::CharactersListWithRemodelingMessage()
{
  m_type = MessageEnum::CHARACTERSLISTWITHREMODELINGMESSAGE;
}

