#include "GameFightEndMessage.h"

void GameFightEndMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightEndMessage(param1);
}

void GameFightEndMessage::serializeAs_GameFightEndMessage(Writer *param1)
{
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameFightEndMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
  }
  else
  {
    param1->writeInt((int)this->duration);
    param1->writeShort((short)this->ageBonus);
    param1->writeShort((short)this->lootShareLimitMalus);
    param1->writeShort((short)this->results.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->results.size())
    {
      param1->writeShort((short)qSharedPointerCast<FightResultListEntry>(this->results[_loc2_])->getTypes().last());
      qSharedPointerCast<FightResultListEntry>(this->results[_loc2_])->serialize(param1);
      _loc2_++;
    }
    param1->writeShort((short)this->namedPartyTeamsOutcomes.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->namedPartyTeamsOutcomes.size())
    {
      (this->namedPartyTeamsOutcomes[_loc3_]).serializeAs_NamedPartyTeamWithOutcome(param1);
      _loc3_++;
    }
    return;
  }
}

void GameFightEndMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightEndMessage(param1);
}

void GameFightEndMessage::deserializeAs_GameFightEndMessage(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<FightResultListEntry> _loc7_ ;
  NamedPartyTeamWithOutcome _loc8_ ;
  this->duration = param1->readInt();
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameFightEndMessage -"<<"Forbidden value (" << this->duration << ") on element of GameFightEndMessage.duration.";
  }
  else
  {
    this->ageBonus = param1->readShort();
    this->lootShareLimitMalus = param1->readShort();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readUShort();
      _loc7_ = qSharedPointerCast<FightResultListEntry>(ClassManagerSingleton::get()->getClass(_loc6_));
      _loc7_->deserialize(param1);
      this->results.append(_loc7_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc8_ = NamedPartyTeamWithOutcome();
      _loc8_.deserialize(param1);
      this->namedPartyTeamsOutcomes.append(_loc8_);
      _loc5_++;
    }
    return;
  }
}

GameFightEndMessage::GameFightEndMessage()
{
  m_type = MessageEnum::GAMEFIGHTENDMESSAGE;
}

