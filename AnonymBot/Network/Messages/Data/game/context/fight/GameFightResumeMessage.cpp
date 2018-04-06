#include "GameFightResumeMessage.h"

void GameFightResumeMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightResumeMessage(param1);
}

void GameFightResumeMessage::serializeAs_GameFightResumeMessage(Writer *param1)
{
  GameFightSpectateMessage::serializeAs_GameFightSpectateMessage(param1);
  param1->writeShort((short)this->spellCooldowns.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->spellCooldowns.size())
  {
    (this->spellCooldowns[_loc2_]).serializeAs_GameFightSpellCooldown(param1);
    _loc2_++;
  }
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->summonCount << ") on element summonCount.";
  }
  else
  {
    param1->writeByte(this->summonCount);
    if(this->bombCount < 0)
    {
      qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->bombCount << ") on element bombCount.";
    }
    else
    {
      param1->writeByte(this->bombCount);
      return;
    }
  }
}

void GameFightResumeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightResumeMessage(param1);
}

void GameFightResumeMessage::deserializeAs_GameFightResumeMessage(Reader *param1)
{
  GameFightSpellCooldown _loc4_ ;
  GameFightSpectateMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = GameFightSpellCooldown();
    _loc4_.deserialize(param1);
    this->spellCooldowns.append(_loc4_);
    _loc3_++;
  }
  this->summonCount = param1->readByte();
  if(this->summonCount < 0)
  {
    qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->summonCount << ") on element of GameFightResumeMessage.summonCount.";
  }
  else
  {
    this->bombCount = param1->readByte();
    if(this->bombCount < 0)
    {
      qDebug()<<"ERREUR - GameFightResumeMessage -"<<"Forbidden value (" << this->bombCount << ") on element of GameFightResumeMessage.bombCount.";
    }
    else
    {
      return;
    }
  }
}

GameFightResumeMessage::GameFightResumeMessage()
{
  m_type = MessageEnum::GAMEFIGHTRESUMEMESSAGE;
}

