#include "GameActionFightCloseCombatMessage.h"

void GameActionFightCloseCombatMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightCloseCombatMessage(param1);
}

void GameActionFightCloseCombatMessage::serializeAs_GameActionFightCloseCombatMessage(Writer *param1)
{
  AbstractGameActionFightTargetedAbilityMessage::serializeAs_AbstractGameActionFightTargetedAbilityMessage(param1);
  if(this->weaponGenericId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCloseCombatMessage -"<<"Forbidden value (" << this->weaponGenericId << ") on element weaponGenericId.";
  }
  else
  {
    param1->writeVarShort((int)this->weaponGenericId);
    return;
  }
}

void GameActionFightCloseCombatMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightCloseCombatMessage(param1);
}

void GameActionFightCloseCombatMessage::deserializeAs_GameActionFightCloseCombatMessage(Reader *param1)
{
  AbstractGameActionFightTargetedAbilityMessage::deserialize(param1);
  this->weaponGenericId = param1->readVarUhShort();
  if(this->weaponGenericId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCloseCombatMessage -"<<"Forbidden value (" << this->weaponGenericId << ") on element of GameActionFightCloseCombatMessage.weaponGenericId.";
  }
  else
  {
    return;
  }
}

GameActionFightCloseCombatMessage::GameActionFightCloseCombatMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCLOSECOMBATMESSAGE;
}

