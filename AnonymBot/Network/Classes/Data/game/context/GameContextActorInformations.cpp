#include "GameContextActorInformations.h"

void GameContextActorInformations::serialize(Writer *param1)
{
  this->serializeAs_GameContextActorInformations(param1);
}

void GameContextActorInformations::serializeAs_GameContextActorInformations(Writer *param1)
{
  if(this->contextualId < -9.007199254740992E15 || this->contextualId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextActorInformations -"<<"Forbidden value (" << this->contextualId << ") on element contextualId.";
  }
  else
  {
    param1->writeDouble(this->contextualId);
    this->look->serializeAs_EntityLook(param1);
    param1->writeShort((short)this->disposition->getTypes().last());
    this->disposition->serialize(param1);
    return;
  }
}

void GameContextActorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextActorInformations(param1);
}

void GameContextActorInformations::deserializeAs_GameContextActorInformations(Reader *param1)
{
  this->contextualId = param1->readDouble();
  if(this->contextualId < -9.007199254740992E15 || this->contextualId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextActorInformations -"<<"Forbidden value (" << this->contextualId << ") on element of GameContextActorInformations.contextualId.";
  }
  else
  {
    this->look = QSharedPointer<EntityLook>(new EntityLook() );
    this->look->deserialize(param1);
    uint _loc2_ = param1->readUShort();
    this->disposition = qSharedPointerCast<EntityDispositionInformations>(ClassManagerSingleton::get()->getClass(_loc2_));
    this->disposition->deserialize(param1);
    return;
  }
}

GameContextActorInformations::GameContextActorInformations()
{
  m_types<<ClassEnum::GAMECONTEXTACTORINFORMATIONS;
}

bool GameContextActorInformations::operator==(const GameContextActorInformations &compared)
{
  if(contextualId == compared.contextualId)
  if(look == compared.look)
  if(disposition == compared.disposition)
  return true;
  
  return false;
}

