#include "CharacterRemodelingInformation.h"

void CharacterRemodelingInformation::serialize(Writer *param1)
{
  this->serializeAs_CharacterRemodelingInformation(param1);
}

void CharacterRemodelingInformation::serializeAs_CharacterRemodelingInformation(Writer *param1)
{
  AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(param1);
  param1->writeUTF(this->name);
  param1->writeByte(this->breed);
  param1->writeBool(this->sex);
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterRemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  else
  {
    param1->writeVarShort((int)this->cosmeticId);
    param1->writeShort((short)this->colors.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->colors.size())
    {
      param1->writeInt((int)this->colors[_loc2_]);
      _loc2_++;
    }
    return;
  }
}

void CharacterRemodelingInformation::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterRemodelingInformation(param1);
}

void CharacterRemodelingInformation::deserializeAs_CharacterRemodelingInformation(Reader *param1)
{
  auto _loc4_ = 0;
  AbstractCharacterInformation::deserialize(param1);
  this->name = param1->readUTF();
  this->breed = param1->readByte();
  this->sex = param1->readBool();
  this->cosmeticId = param1->readVarUhShort();
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterRemodelingInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element of CharacterRemodelingInformation.cosmeticId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readInt();
      this->colors.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

CharacterRemodelingInformation::CharacterRemodelingInformation()
{
  m_types<<ClassEnum::CHARACTERREMODELINGINFORMATION;
}

bool CharacterRemodelingInformation::operator==(const CharacterRemodelingInformation &compared)
{
  if(name == compared.name)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(cosmeticId == compared.cosmeticId)
  if(colors == compared.colors)
  return true;
  
  return false;
}

