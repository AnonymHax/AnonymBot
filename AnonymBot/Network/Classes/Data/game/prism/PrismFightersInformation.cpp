#include "PrismFightersInformation.h"

void PrismFightersInformation::serialize(Writer *param1)
{
  this->serializeAs_PrismFightersInformation(param1);
}

void PrismFightersInformation::serializeAs_PrismFightersInformation(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightersInformation -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    this->waitingForHelpInfo.serializeAs_ProtectedEntityWaitingForHelpInfo(param1);
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
    return;
  }
}

void PrismFightersInformation::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightersInformation(param1);
}

void PrismFightersInformation::deserializeAs_PrismFightersInformation(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _loc7_ ;
  uint _loc8_ = 0;
  QSharedPointer<CharacterMinimalPlusLookInformations> _loc9_ ;
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightersInformation -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightersInformation.subAreaId.";
  }
  else
  {
    this->waitingForHelpInfo = ProtectedEntityWaitingForHelpInfo();
    this->waitingForHelpInfo.deserialize(param1);
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
    return;
  }
}

PrismFightersInformation::PrismFightersInformation()
{
  m_types<<ClassEnum::PRISMFIGHTERSINFORMATION;
}

bool PrismFightersInformation::operator==(const PrismFightersInformation &compared)
{
  if(subAreaId == compared.subAreaId)
  if(waitingForHelpInfo == compared.waitingForHelpInfo)
  if(allyCharactersInformations == compared.allyCharactersInformations)
  if(enemyCharactersInformations == compared.enemyCharactersInformations)
  return true;
  
  return false;
}

