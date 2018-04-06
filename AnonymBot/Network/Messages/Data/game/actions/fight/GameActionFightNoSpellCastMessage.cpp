#include "GameActionFightNoSpellCastMessage.h"

void GameActionFightNoSpellCastMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightNoSpellCastMessage(param1);
}

void GameActionFightNoSpellCastMessage::serializeAs_GameActionFightNoSpellCastMessage(Writer *param1)
{
  if(this->spellLevelId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightNoSpellCastMessage -"<<"Forbidden value (" << this->spellLevelId << ") on element spellLevelId.";
  }
  else
  {
    param1->writeVarInt((int)this->spellLevelId);
    return;
  }
}

void GameActionFightNoSpellCastMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightNoSpellCastMessage(param1);
}

void GameActionFightNoSpellCastMessage::deserializeAs_GameActionFightNoSpellCastMessage(Reader *param1)
{
  this->spellLevelId = param1->readVarUhInt();
  if(this->spellLevelId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightNoSpellCastMessage -"<<"Forbidden value (" << this->spellLevelId << ") on element of GameActionFightNoSpellCastMessage.spellLevelId.";
  }
  else
  {
    return;
  }
}

GameActionFightNoSpellCastMessage::GameActionFightNoSpellCastMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTNOSPELLCASTMESSAGE;
}

