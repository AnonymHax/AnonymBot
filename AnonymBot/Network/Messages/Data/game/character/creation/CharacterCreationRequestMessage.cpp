#include "CharacterCreationRequestMessage.h"

void CharacterCreationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterCreationRequestMessage(param1);
}

void CharacterCreationRequestMessage::serializeAs_CharacterCreationRequestMessage(Writer *param1)
{
  param1->writeUTF(this->name);
  param1->writeByte(this->breed);
  param1->writeBool(this->sex);
  uint _loc2_ = 0;
  while(_loc2_ < 5)
  {
    param1->writeInt((int)this->colors[_loc2_]);
    _loc2_++;
  }
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  else
  {
    param1->writeVarShort((int)this->cosmeticId);
    return;
  }
}

void CharacterCreationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterCreationRequestMessage(param1);
}

void CharacterCreationRequestMessage::deserializeAs_CharacterCreationRequestMessage(Reader *param1)
{
  this->name = param1->readUTF();
  this->breed = param1->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::HUPPERMAGE)
  {
    qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->breed << ") on element of CharacterCreationRequestMessage.breed.";
  }
  else
  {
    this->sex = param1->readBool();
    uint _loc2_ = 0;
    while(_loc2_ < 5)
    {
      this->colors<<param1->readInt();
      _loc2_++;
    }
    this->cosmeticId = param1->readVarUhShort();
    if(this->cosmeticId < 0)
    {
      qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->cosmeticId << ") on element of CharacterCreationRequestMessage.cosmeticId.";
    }
    else
    {
      return;
    }
  }
}

CharacterCreationRequestMessage::CharacterCreationRequestMessage()
{
  m_type = MessageEnum::CHARACTERCREATIONREQUESTMESSAGE;
}

