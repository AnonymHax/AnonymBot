#include "MapComplementaryInformationsDataMessage.h"

void MapComplementaryInformationsDataMessage::serialize(Writer *param1)
{
  this->serializeAs_MapComplementaryInformationsDataMessage(param1);
}

void MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->mapId < 0)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
    }
    else
    {
      param1->writeInt((int)this->mapId);
      param1->writeShort((short)this->houses.size());
      uint _loc2_ = 0;
      while(_loc2_ < this->houses.size())
      {
        param1->writeShort((short)qSharedPointerCast<HouseInformations>(this->houses[_loc2_])->getTypes().last());
        qSharedPointerCast<HouseInformations>(this->houses[_loc2_])->serialize(param1);
        _loc2_++;
      }
      param1->writeShort((short)this->actors.size());
      uint _loc3_ = 0;
      while(_loc3_ < this->actors.size())
      {
        param1->writeShort((short)qSharedPointerCast<GameRolePlayActorInformations>(this->actors[_loc3_])->getTypes().last());
        qSharedPointerCast<GameRolePlayActorInformations>(this->actors[_loc3_])->serialize(param1);
        _loc3_++;
      }
      param1->writeShort((short)this->interactiveElements.size());
      uint _loc4_ = 0;
      while(_loc4_ < this->interactiveElements.size())
      {
        param1->writeShort((short)qSharedPointerCast<InteractiveElement>(this->interactiveElements[_loc4_])->getTypes().last());
        qSharedPointerCast<InteractiveElement>(this->interactiveElements[_loc4_])->serialize(param1);
        _loc4_++;
      }
      param1->writeShort((short)this->statedElements.size());
      uint _loc5_ = 0;
      while(_loc5_ < this->statedElements.size())
      {
        (this->statedElements[_loc5_]).serializeAs_StatedElement(param1);
        _loc5_++;
      }
      param1->writeShort((short)this->obstacles.size());
      uint _loc6_ = 0;
      while(_loc6_ < this->obstacles.size())
      {
        (this->obstacles[_loc6_]).serializeAs_MapObstacle(param1);
        _loc6_++;
      }
      param1->writeShort((short)this->fights.size());
      uint _loc7_ = 0;
      while(_loc7_ < this->fights.size())
      {
        qSharedPointerCast<FightCommonInformations>(this->fights[_loc7_])->serializeAs_FightCommonInformations(param1);
        _loc7_++;
      }
      param1->writeBool(this->hasAggressiveMonsters);
      return;
    }
  }
}

void MapComplementaryInformationsDataMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MapComplementaryInformationsDataMessage(param1);
}

void MapComplementaryInformationsDataMessage::deserializeAs_MapComplementaryInformationsDataMessage(Reader *param1)
{
  uint _loc14_ = 0;
  QSharedPointer<HouseInformations> _loc15_ ;
  uint _loc16_ = 0;
  QSharedPointer<GameRolePlayActorInformations> _loc17_ ;
  uint _loc18_ = 0;
  QSharedPointer<InteractiveElement> _loc19_ ;
  StatedElement _loc20_ ;
  MapObstacle _loc21_ ;
  QSharedPointer<FightCommonInformations> _loc22_ ;
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of MapComplementaryInformationsDataMessage.subAreaId.";
  }
  else
  {
    this->mapId = param1->readInt();
    if(this->mapId < 0)
    {
      qDebug()<<"ERREUR - MapComplementaryInformationsDataMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapComplementaryInformationsDataMessage.mapId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      uint _loc3_ = 0;
      while(_loc3_ < _loc2_)
      {
        _loc14_ = param1->readUShort();
        _loc15_ = qSharedPointerCast<HouseInformations>(ClassManagerSingleton::get()->getClass(_loc14_));
        _loc15_->deserialize(param1);
        this->houses.append(_loc15_);
        _loc3_++;
      }
      uint _loc4_ = param1->readUShort();
      uint _loc5_ = 0;
      while(_loc5_ < _loc4_)
      {
        _loc16_ = param1->readUShort();
        _loc17_ = qSharedPointerCast<GameRolePlayActorInformations>(ClassManagerSingleton::get()->getClass(_loc16_));
        _loc17_->deserialize(param1);
        this->actors.append(_loc17_);
        _loc5_++;
      }
      uint _loc6_ = param1->readUShort();
      uint _loc7_ = 0;
      while(_loc7_ < _loc6_)
      {
        _loc18_ = param1->readUShort();
        _loc19_ = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_loc18_));
        _loc19_->deserialize(param1);
        this->interactiveElements.append(_loc19_);
        _loc7_++;
      }
      uint _loc8_ = param1->readUShort();
      uint _loc9_ = 0;
      while(_loc9_ < _loc8_)
      {
        _loc20_ = StatedElement();
        _loc20_.deserialize(param1);
        this->statedElements.append(_loc20_);
        _loc9_++;
      }
      uint _loc10_ = param1->readUShort();
      uint _loc11_ = 0;
      while(_loc11_ < _loc10_)
      {
        _loc21_ = MapObstacle();
        _loc21_.deserialize(param1);
        this->obstacles.append(_loc21_);
        _loc11_++;
      }
      uint _loc12_ = param1->readUShort();
      uint _loc13_ = 0;
      while(_loc13_ < _loc12_)
      {
        _loc22_ = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
        _loc22_->deserialize(param1);
        this->fights.append(_loc22_);
        _loc13_++;
      }
      this->hasAggressiveMonsters = param1->readBool();
      return;
    }
  }
}

MapComplementaryInformationsDataMessage::MapComplementaryInformationsDataMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAMESSAGE;
}

