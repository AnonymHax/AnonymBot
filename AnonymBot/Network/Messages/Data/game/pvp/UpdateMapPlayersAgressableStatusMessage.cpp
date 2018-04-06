#include "UpdateMapPlayersAgressableStatusMessage.h"

void UpdateMapPlayersAgressableStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_UpdateMapPlayersAgressableStatusMessage(param1);
}

void UpdateMapPlayersAgressableStatusMessage::serializeAs_UpdateMapPlayersAgressableStatusMessage(Writer *param1)
{
  param1->writeShort((short)this->playerIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->playerIds.size())
  {
    if(this->playerIds[_loc2_] < 0 || this->playerIds[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << this->playerIds[_loc2_] << ") on element 1 (starting at 1) of playerIds.";
    }
    else
    {
      param1->writeVarLong((double)this->playerIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->enable.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->enable.size())
  {
    param1->writeByte(this->enable[_loc3_]);
    _loc3_++;
  }
}

void UpdateMapPlayersAgressableStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateMapPlayersAgressableStatusMessage(param1);
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAs_UpdateMapPlayersAgressableStatusMessage(Reader *param1)
{
  auto _loc6_ = NULL;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhLong();
    if(_loc6_ < 0 || _loc6_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of playerIds.";
    }
    else
    {
      this->playerIds.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readByte();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - UpdateMapPlayersAgressableStatusMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of enable.";
    }
    else
    {
      this->enable.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
}

UpdateMapPlayersAgressableStatusMessage::UpdateMapPlayersAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE;
}

