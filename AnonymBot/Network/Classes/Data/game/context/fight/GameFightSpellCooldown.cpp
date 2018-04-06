#include "GameFightSpellCooldown.h"

void GameFightSpellCooldown::serialize(Writer *param1)
{
  this->serializeAs_GameFightSpellCooldown(param1);
}

void GameFightSpellCooldown::serializeAs_GameFightSpellCooldown(Writer *param1)
{
  param1->writeInt((int)this->spellId);
  if(this->cooldown < 0)
  {
    qDebug()<<"ERREUR - GameFightSpellCooldown -"<<"Forbidden value (" << this->cooldown << ") on element cooldown.";
  }
  else
  {
    param1->writeByte(this->cooldown);
    return;
  }
}

void GameFightSpellCooldown::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightSpellCooldown(param1);
}

void GameFightSpellCooldown::deserializeAs_GameFightSpellCooldown(Reader *param1)
{
  this->spellId = param1->readInt();
  this->cooldown = param1->readByte();
  if(this->cooldown < 0)
  {
    qDebug()<<"ERREUR - GameFightSpellCooldown -"<<"Forbidden value (" << this->cooldown << ") on element of GameFightSpellCooldown.cooldown.";
  }
  else
  {
    return;
  }
}

GameFightSpellCooldown::GameFightSpellCooldown()
{
  m_types<<ClassEnum::GAMEFIGHTSPELLCOOLDOWN;
}

bool GameFightSpellCooldown::operator==(const GameFightSpellCooldown &compared)
{
  if(spellId == compared.spellId)
  if(cooldown == compared.cooldown)
  return true;
  
  return false;
}

