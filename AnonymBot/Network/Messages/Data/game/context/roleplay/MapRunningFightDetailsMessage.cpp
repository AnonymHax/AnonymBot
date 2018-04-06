#include "MapRunningFightDetailsMessage.h"

void MapRunningFightDetailsMessage::serialize(Writer *param1)
{
  this->serializeAs_MapRunningFightDetailsMessage(param1);
}

void MapRunningFightDetailsMessage::serializeAs_MapRunningFightDetailsMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    param1->writeShort((short)this->attackers.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->attackers.size())
    {
      param1->writeShort((short)qSharedPointerCast<GameFightFighterLightInformations>(this->attackers[_loc2_])->getTypes().last());
      qSharedPointerCast<GameFightFighterLightInformations>(this->attackers[_loc2_])->serialize(param1);
      _loc2_++;
    }
    param1->writeShort((short)this->defenders.size());
    uint _loc3_ = 0;
    while(_loc3_ < this->defenders.size())
    {
      param1->writeShort((short)qSharedPointerCast<GameFightFighterLightInformations>(this->defenders[_loc3_])->getTypes().last());
      qSharedPointerCast<GameFightFighterLightInformations>(this->defenders[_loc3_])->serialize(param1);
      _loc3_++;
    }
    return;
  }
}

void MapRunningFightDetailsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapRunningFightDetailsMessage(param1);
}

void MapRunningFightDetailsMessage::deserializeAs_MapRunningFightDetailsMessage(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<GameFightFighterLightInformations> _loc7_ ;
  uint _loc8_ = 0;
  QSharedPointer<GameFightFighterLightInformations> _loc9_ ;
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsMessage -"<<"Forbidden value (" << this->fightId << ") on element of MapRunningFightDetailsMessage.fightId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readUShort();
      _loc7_ = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_loc6_));
      _loc7_->deserialize(param1);
      this->attackers.append(_loc7_);
      _loc3_++;
    }
    uint _loc4_ = param1->readUShort();
    uint _loc5_ = 0;
    while(_loc5_ < _loc4_)
    {
      _loc8_ = param1->readUShort();
      _loc9_ = qSharedPointerCast<GameFightFighterLightInformations>(ClassManagerSingleton::get()->getClass(_loc8_));
      _loc9_->deserialize(param1);
      this->defenders.append(_loc9_);
      _loc5_++;
    }
    return;
  }
}

MapRunningFightDetailsMessage::MapRunningFightDetailsMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSMESSAGE;
}

