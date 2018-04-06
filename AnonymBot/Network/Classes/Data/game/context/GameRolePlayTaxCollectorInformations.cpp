#include "GameRolePlayTaxCollectorInformations.h"

void GameRolePlayTaxCollectorInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayTaxCollectorInformations(param1);
}

void GameRolePlayTaxCollectorInformations::serializeAs_GameRolePlayTaxCollectorInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  param1->writeShort((short)this->identification->getTypes().last());
  this->identification->serialize(param1);
  if(this->guildLevel < 0 || this->guildLevel > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayTaxCollectorInformations -"<<"Forbidden value (" << this->guildLevel << ") on element guildLevel.";
  }
  else
  {
    param1->writeByte(this->guildLevel);
    param1->writeInt((int)this->taxCollectorAttack);
    return;
  }
}

void GameRolePlayTaxCollectorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayTaxCollectorInformations(param1);
}

void GameRolePlayTaxCollectorInformations::deserializeAs_GameRolePlayTaxCollectorInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->identification = qSharedPointerCast<TaxCollectorStaticInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->identification->deserialize(param1);
  this->guildLevel = param1->readUByte();
  if(this->guildLevel < 0 || this->guildLevel > 255)
  {
    qDebug()<<"ERREUR - GameRolePlayTaxCollectorInformations -"<<"Forbidden value (" << this->guildLevel << ") on element of GameRolePlayTaxCollectorInformations.guildLevel.";
  }
  else
  {
    this->taxCollectorAttack = param1->readInt();
    return;
  }
}

GameRolePlayTaxCollectorInformations::GameRolePlayTaxCollectorInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYTAXCOLLECTORINFORMATIONS;
}

bool GameRolePlayTaxCollectorInformations::operator==(const GameRolePlayTaxCollectorInformations &compared)
{
  if(identification == compared.identification)
  if(guildLevel == compared.guildLevel)
  if(taxCollectorAttack == compared.taxCollectorAttack)
  return true;
  
  return false;
}

