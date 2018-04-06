#include "BasicWhoIsMessage.h"

void BasicWhoIsMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicWhoIsMessage(param1);
}

void BasicWhoIsMessage::serializeAs_BasicWhoIsMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->self);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->verbose);
  param1->writeByte(_loc2_);
  param1->writeByte(this->position);
  param1->writeUTF(this->accountNickname);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    param1->writeUTF(this->playerName);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      param1->writeShort((short)this->areaId);
      param1->writeShort((short)this->serverId);
      param1->writeShort((short)this->originServerId);
      param1->writeShort((short)this->socialGroups.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->socialGroups.size())
      {
        param1->writeShort((short)qSharedPointerCast<AbstractSocialGroupInfos>(this->socialGroups[_loc3_])->getTypes().last());
        qSharedPointerCast<AbstractSocialGroupInfos>(this->socialGroups[_loc3_])->serialize(param1);
        _loc3_++;
      }
      param1->writeByte(this->playerState);
      return;
    }
  }
}

void BasicWhoIsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicWhoIsMessage(param1);
}

void BasicWhoIsMessage::deserializeAs_BasicWhoIsMessage(Reader *param1)
{
  uint _loc5_ = 0;
  QSharedPointer<AbstractSocialGroupInfos> _loc6_ ;
  uint _loc2_ = param1->readByte();
  this->self = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->verbose = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->position = param1->readByte();
  this->accountNickname = param1->readUTF();
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->accountId << ") on element of BasicWhoIsMessage.accountId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerId << ") on element of BasicWhoIsMessage.playerId.";
    }
    else
    {
      this->areaId = param1->readShort();
      this->serverId = param1->readShort();
      this->originServerId = param1->readShort();
      uint _loc3_ = param1->readUShort();
      uint _loc4_ = 0;
      while(_loc4_ < _loc3_)
      {
        _loc5_ = param1->readUShort();
        _loc6_ = qSharedPointerCast<AbstractSocialGroupInfos>(ClassManagerSingleton::get()->getClass(_loc5_));
        _loc6_->deserialize(param1);
        this->socialGroups.append(_loc6_);
        _loc4_++;
      }
      this->playerState = param1->readByte();
      if(this->playerState < 0)
      {
        qDebug()<<"ERREUR - BasicWhoIsMessage -"<<"Forbidden value (" << this->playerState << ") on element of BasicWhoIsMessage.playerState.";
      }
      else
      {
        return;
      }
    }
  }
}

BasicWhoIsMessage::BasicWhoIsMessage()
{
  m_type = MessageEnum::BASICWHOISMESSAGE;
}

