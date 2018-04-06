#include "CharactersListWithModificationsMessage.h"

void CharactersListWithModificationsMessage::serialize(Writer *param1)
{
  this->serializeAs_CharactersListWithModificationsMessage(param1);
}

void CharactersListWithModificationsMessage::serializeAs_CharactersListWithModificationsMessage(Writer *param1)
{
  CharactersListMessage::serializeAs_CharactersListMessage(param1);
  param1->writeShort((short)this->charactersToRecolor.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->charactersToRecolor.size())
  {
    (this->charactersToRecolor[_loc2_]).serializeAs_CharacterToRecolorInformation(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->charactersToRename.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->charactersToRename.size())
  {
    param1->writeInt((int)this->charactersToRename[_loc3_]);
    _loc3_++;
  }
  param1->writeShort((short)this->unusableCharacters.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->unusableCharacters.size())
  {
    param1->writeInt((int)this->unusableCharacters[_loc4_]);
    _loc4_++;
  }
  param1->writeShort((short)this->charactersToRelook.size());
  uint _loc5_ = 0;
  while(_loc5_ < this->charactersToRelook.size())
  {
    (this->charactersToRelook[_loc5_]).serializeAs_CharacterToRelookInformation(param1);
    _loc5_++;
  }
}

void CharactersListWithModificationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharactersListWithModificationsMessage(param1);
}

void CharactersListWithModificationsMessage::deserializeAs_CharactersListWithModificationsMessage(Reader *param1)
{
  CharacterToRecolorInformation _loc10_ ;
  auto _loc11_ = 0;
  auto _loc12_ = 0;
  CharacterToRelookInformation _loc13_ ;
  CharactersListMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc10_ = CharacterToRecolorInformation();
    _loc10_.deserialize(param1);
    this->charactersToRecolor.append(_loc10_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc11_ = param1->readInt();
    this->charactersToRename.append(_loc11_);
    _loc5_++;
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc12_ = param1->readInt();
    this->unusableCharacters.append(_loc12_);
    _loc7_++;
  }
  uint _loc8_ = param1->readUShort();
  uint _loc9_ = 0;
  while(_loc9_ < _loc8_)
  {
    _loc13_ = CharacterToRelookInformation();
    _loc13_.deserialize(param1);
    this->charactersToRelook.append(_loc13_);
    _loc9_++;
  }
}

CharactersListWithModificationsMessage::CharactersListWithModificationsMessage()
{
  m_type = MessageEnum::CHARACTERSLISTWITHMODIFICATIONSMESSAGE;
}

