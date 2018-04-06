#include "AbstractCharacterToRefurbishInformation.h"

void AbstractCharacterToRefurbishInformation::serialize(Writer *param1)
{
  this->serializeAs_AbstractCharacterToRefurbishInformation(param1);
}

void AbstractCharacterToRefurbishInformation::serializeAs_AbstractCharacterToRefurbishInformation(Writer *param1)
{
  AbstractCharacterInformation::serializeAs_AbstractCharacterInformation(param1);
  param1->writeShort((short)this->colors.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->colors.size())
  {
    param1->writeInt((int)this->colors[_loc2_]);
    _loc2_++;
  }
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - AbstractCharacterToRefurbishInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  else
  {
    param1->writeVarInt((int)this->cosmeticId);
    return;
  }
}

void AbstractCharacterToRefurbishInformation::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractCharacterToRefurbishInformation(param1);
}

void AbstractCharacterToRefurbishInformation::deserializeAs_AbstractCharacterToRefurbishInformation(Reader *param1)
{
  auto _loc4_ = 0;
  AbstractCharacterInformation::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readInt();
    this->colors.append(_loc4_);
    _loc3_++;
  }
  this->cosmeticId = param1->readVarUhInt();
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - AbstractCharacterToRefurbishInformation -"<<"Forbidden value (" << this->cosmeticId << ") on element of AbstractCharacterToRefurbishInformation.cosmeticId.";
  }
  else
  {
    return;
  }
}

AbstractCharacterToRefurbishInformation::AbstractCharacterToRefurbishInformation()
{
  m_types<<ClassEnum::ABSTRACTCHARACTERTOREFURBISHINFORMATION;
}

bool AbstractCharacterToRefurbishInformation::operator==(const AbstractCharacterToRefurbishInformation &compared)
{
  if(colors == compared.colors)
  if(cosmeticId == compared.cosmeticId)
  return true;
  
  return false;
}

