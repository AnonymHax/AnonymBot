#include "PlayerStatusUpdateMessage.h"

void PlayerStatusUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PlayerStatusUpdateMessage(param1);
}

void PlayerStatusUpdateMessage::serializeAs_PlayerStatusUpdateMessage(Writer *param1)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      param1->writeShort((short)this->status->getTypes().last());
      this->status->serialize(param1);
      return;
    }
  }
}

void PlayerStatusUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PlayerStatusUpdateMessage(param1);
}

void PlayerStatusUpdateMessage::deserializeAs_PlayerStatusUpdateMessage(Reader *param1)
{
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element of PlayerStatusUpdateMessage.accountId.";
  }
  else
  {
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of PlayerStatusUpdateMessage.playerId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->status->deserialize(param1);
      return;
    }
  }
}

PlayerStatusUpdateMessage::PlayerStatusUpdateMessage()
{
  m_type = MessageEnum::PLAYERSTATUSUPDATEMESSAGE;
}

