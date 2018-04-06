#include "HavenBagFurnituresRequestMessage.h"

void HavenBagFurnituresRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HavenBagFurnituresRequestMessage(param1);
}

void HavenBagFurnituresRequestMessage::serializeAs_HavenBagFurnituresRequestMessage(Writer *param1)
{
  param1->writeShort((short)this->cellIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->cellIds.size())
  {
    if(this->cellIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << this->cellIds[_loc2_] << ") on element 1 (starting at 1) of cellIds.";
    }
    else
    {
      param1->writeVarShort((int)this->cellIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->funitureIds.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->funitureIds.size())
  {
    param1->writeInt((int)this->funitureIds[_loc3_]);
    _loc3_++;
  }
  param1->writeShort((short)this->orientations.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->orientations.size())
  {
    if(this->orientations[_loc4_] < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << this->orientations[_loc4_] << ") on element 3 (starting at 1) of orientations.";
    }
    else
    {
      param1->writeByte(this->orientations[_loc4_]);
      _loc4_++;
      continue;
    }
  }
}

void HavenBagFurnituresRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HavenBagFurnituresRequestMessage(param1);
}

void HavenBagFurnituresRequestMessage::deserializeAs_HavenBagFurnituresRequestMessage(Reader *param1)
{
  uint _loc8_ = 0;
  auto _loc9_ = 0;
  uint _loc10_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc8_ = param1->readVarUhShort();
    if(_loc8_ < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _loc8_ << ") on elements of cellIds.";
    }
    else
    {
      this->cellIds.append(_loc8_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc9_ = param1->readInt();
    this->funitureIds.append(_loc9_);
    _loc5_++;
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc10_ = param1->readByte();
    if(_loc10_ < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnituresRequestMessage -"<<"Forbidden value (" << _loc10_ << ") on elements of orientations.";
    }
    else
    {
      this->orientations.append(_loc10_);
      _loc7_++;
      continue;
    }
  }
}

HavenBagFurnituresRequestMessage::HavenBagFurnituresRequestMessage()
{
  m_type = MessageEnum::HAVENBAGFURNITURESREQUESTMESSAGE;
}

