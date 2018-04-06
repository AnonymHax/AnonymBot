#include "TaxCollectorFightersInformation.h"

void TaxCollectorFightersInformation::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorFightersInformation(param1);
}

void TaxCollectorFightersInformation::serializeAs_TaxCollectorFightersInformation(Writer *param1)
{
  param1->writeInt((int)this->collectorId);
  param1->writeShort((short)this->allyCharactersInformations.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->allyCharactersInformations.size())
  {
    param1->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_loc2_])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->allyCharactersInformations[_loc2_])->serialize(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->enemyCharactersInformations.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->enemyCharactersInformations.size())
  {
    param1->writeShort((short)qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_loc3_])->getTypes().last());
    qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->enemyCharactersInformations[_loc3_])->serialize(param1);
    _loc3_++;
  }
}

void TaxCollectorFightersInformation::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorFightersInformation(param1);
}

void TaxCollectorFightersInformation::deserializeAs_TaxCollectorFightersInformation(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _loc7_ ;
  uint _loc8_ = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _loc9_ ;
  this->collectorId = param1->readInt();
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readUShort();
    _loc7_ = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_loc6_));
    _loc7_->deserialize(param1);
    this->allyCharactersInformations.append(_loc7_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc8_ = param1->readUShort();
    _loc9_ = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_loc8_));
    _loc9_->deserialize(param1);
    this->enemyCharactersInformations.append(_loc9_);
    _loc5_++;
  }
}

TaxCollectorFightersInformation::TaxCollectorFightersInformation()
{
  m_types<<ClassEnum::TAXCOLLECTORFIGHTERSINFORMATION;
}

bool TaxCollectorFightersInformation::operator==(const TaxCollectorFightersInformation &compared)
{
  if(collectorId == compared.collectorId)
  if(allyCharactersInformations == compared.allyCharactersInformations)
  if(enemyCharactersInformations == compared.enemyCharactersInformations)
  return true;
  
  return false;
}

