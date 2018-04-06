#include "TeleportDestinationsListMessage.h"

void TeleportDestinationsListMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportDestinationsListMessage(param1);
}

void TeleportDestinationsListMessage::serializeAs_TeleportDestinationsListMessage(Writer *param1)
{
  param1->writeByte(this->teleporterType);
  param1->writeShort((short)this->mapIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->mapIds.size())
  {
    if(this->mapIds[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << this->mapIds[_loc2_] << ") on element 2 (starting at 1) of mapIds.";
    }
    else
    {
      param1->writeInt((int)this->mapIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->subAreaIds.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->subAreaIds.size())
  {
    if(this->subAreaIds[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << this->subAreaIds[_loc3_] << ") on element 3 (starting at 1) of subAreaIds.";
    }
    else
    {
      param1->writeVarShort((int)this->subAreaIds[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeShort((short)this->costs.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->costs.size())
  {
    if(this->costs[_loc4_] < 0)
    {
      qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << this->costs[_loc4_] << ") on element 4 (starting at 1) of costs.";
    }
    else
    {
      param1->writeVarShort((int)this->costs[_loc4_]);
      _loc4_++;
      continue;
    }
  }
  param1->writeShort((short)this->destTeleporterType.size());
  uint _loc5_ = 0;
  while(_loc5_ < this->destTeleporterType.size())
  {
    param1->writeByte(this->destTeleporterType[_loc5_]);
    _loc5_++;
  }
}

void TeleportDestinationsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportDestinationsListMessage(param1);
}

void TeleportDestinationsListMessage::deserializeAs_TeleportDestinationsListMessage(Reader *param1)
{
  uint _loc10_ = 0;
  uint _loc11_ = 0;
  uint _loc12_ = 0;
  uint _loc13_ = 0;
  this->teleporterType = param1->readByte();
  if(this->teleporterType < 0)
  {
    qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << this->teleporterType << ") on element of TeleportDestinationsListMessage.teleporterType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc10_ = param1->readInt();
      if(_loc10_ < 0)
      {
        qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << _loc10_ << ") on elements of mapIds.";
      }
      else
      {
        this->mapIds.append(_loc10_);
        _loc3_++;
        continue;
      }
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc11_ = param1->readVarUhShort();
      if(_loc11_ < 0)
      {
        qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << _loc11_ << ") on elements of subAreaIds.";
      }
      else
      {
        this->subAreaIds.append(_loc11_);
        _loc5_++;
        continue;
      }
    }
    uint _loc6_ = param1->readUShort();
    uint _loc7_ = 0;
    while(_loc7_ < _loc6_)
    {
      _loc12_ = param1->readVarUhShort();
      if(_loc12_ < 0)
      {
        qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << _loc12_ << ") on elements of costs.";
      }
      else
      {
        this->costs.append(_loc12_);
        _loc7_++;
        continue;
      }
    }
    uint _loc8_ = param1->readUShort();
    uint _loc9_ = 0;
    while(_loc9_ < _loc8_)
    {
      _loc13_ = param1->readByte();
      if(_loc13_ < 0)
      {
        qDebug()<<"ERREUR - TeleportDestinationsListMessage -"<<"Forbidden value (" << _loc13_ << ") on elements of destTeleporterType.";
      }
      else
      {
        this->destTeleporterType.append(_loc13_);
        _loc9_++;
        continue;
      }
    }
    return;
  }
}

TeleportDestinationsListMessage::TeleportDestinationsListMessage()
{
  m_type = MessageEnum::TELEPORTDESTINATIONSLISTMESSAGE;
}

