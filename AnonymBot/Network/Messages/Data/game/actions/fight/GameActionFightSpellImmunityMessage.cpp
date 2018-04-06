#include "GameActionFightSpellImmunityMessage.h"

void GameActionFightSpellImmunityMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightSpellImmunityMessage(param1);
}

void GameActionFightSpellImmunityMessage::serializeAs_GameActionFightSpellImmunityMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
    }
    else
    {
      param1->writeVarShort((int)this->spellId);
      return;
    }
  }
}

void GameActionFightSpellImmunityMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightSpellImmunityMessage(param1);
}

void GameActionFightSpellImmunityMessage::deserializeAs_GameActionFightSpellImmunityMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSpellImmunityMessage.targetId.";
  }
  else
  {
    this->spellId = param1->readVarUhShort();
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightSpellImmunityMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellImmunityMessage.spellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightSpellImmunityMessage::GameActionFightSpellImmunityMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLIMMUNITYMESSAGE;
}

