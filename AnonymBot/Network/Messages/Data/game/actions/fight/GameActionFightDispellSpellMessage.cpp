#include "GameActionFightDispellSpellMessage.h"

void GameActionFightDispellSpellMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDispellSpellMessage(param1);
}

void GameActionFightDispellSpellMessage::serializeAs_GameActionFightDispellSpellMessage(Writer *param1)
{
  GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(param1);
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellSpellMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    return;
  }
}

void GameActionFightDispellSpellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDispellSpellMessage(param1);
}

void GameActionFightDispellSpellMessage::deserializeAs_GameActionFightDispellSpellMessage(Reader *param1)
{
  GameActionFightDispellMessage::deserialize(param1);
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellSpellMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightDispellSpellMessage.spellId.";
  }
  else
  {
    return;
  }
}

GameActionFightDispellSpellMessage::GameActionFightDispellSpellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLSPELLMESSAGE;
}

