#include "TeleportBuddiesRequestedMessage.h"

void TeleportBuddiesRequestedMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportBuddiesRequestedMessage(param1);
}

void TeleportBuddiesRequestedMessage::serializeAs_TeleportBuddiesRequestedMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    if(this->inviterId < 0 || this->inviterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->inviterId << ") on element inviterId.";
    }
    else
    {
      param1->writeVarLong((double)this->inviterId);
      param1->writeShort((short)this->invalidBuddiesIds.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->invalidBuddiesIds.size())
      {
        if(this->invalidBuddiesIds[_loc2_] < 0 || this->invalidBuddiesIds[_loc2_] > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->invalidBuddiesIds[_loc2_] << ") on element 3 (starting at 1) of invalidBuddiesIds.";
        }
        else
        {
          param1->writeVarLong((double)this->invalidBuddiesIds[_loc2_]);
          _loc2_++;
          continue;
        }
      }
      return;
    }
  }
}

void TeleportBuddiesRequestedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportBuddiesRequestedMessage(param1);
}

void TeleportBuddiesRequestedMessage::deserializeAs_TeleportBuddiesRequestedMessage(Reader *param1)
{
  auto _loc4_ = NULL;
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportBuddiesRequestedMessage.dungeonId.";
  }
  else
  {
    this->inviterId = param1->readVarUhLong();
    if(this->inviterId < 0 || this->inviterId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << this->inviterId << ") on element of TeleportBuddiesRequestedMessage.inviterId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc4_ = param1->readVarUhLong();
        if(_loc4_ < 0 || _loc4_ > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - TeleportBuddiesRequestedMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of invalidBuddiesIds.";
        }
        else
        {
          this->invalidBuddiesIds.append(_loc4_);
          _loc3_++;
          continue;
        }
      }
      return;
    }
  }
}

TeleportBuddiesRequestedMessage::TeleportBuddiesRequestedMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESREQUESTEDMESSAGE;
}

