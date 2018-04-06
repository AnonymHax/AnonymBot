#include "GameFightJoinMessage.h"

void GameFightJoinMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightJoinMessage(param1);
}

void GameFightJoinMessage::serializeAs_GameFightJoinMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isTeamPhase);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->canBeCancelled);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->canSayReady);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->isFightStarted);
  param1->writeByte(_loc2_);
  if(this->timeMaxBeforeFightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->timeMaxBeforeFightStart << ") on element timeMaxBeforeFightStart.";
  }
  else
  {
    param1->writeShort((short)this->timeMaxBeforeFightStart);
    param1->writeByte(this->fightType);
    return;
  }
}

void GameFightJoinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightJoinMessage(param1);
}

void GameFightJoinMessage::deserializeAs_GameFightJoinMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->isTeamPhase = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->canBeCancelled = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->canSayReady = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->isFightStarted = BooleanByteWrapper::getFlag(_loc2_, 3);
  this->timeMaxBeforeFightStart = param1->readShort();
  if(this->timeMaxBeforeFightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->timeMaxBeforeFightStart << ") on element of GameFightJoinMessage.timeMaxBeforeFightStart.";
  }
  else
  {
    this->fightType = param1->readByte();
    if(this->fightType < 0)
    {
      qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->fightType << ") on element of GameFightJoinMessage.fightType.";
    }
    else
    {
      return;
    }
  }
}

GameFightJoinMessage::GameFightJoinMessage()
{
  m_type = MessageEnum::GAMEFIGHTJOINMESSAGE;
}

