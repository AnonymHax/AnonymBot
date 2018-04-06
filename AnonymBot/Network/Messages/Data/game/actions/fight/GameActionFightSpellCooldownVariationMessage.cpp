#include "GameActionFightSpellCooldownVariationMessage.h"

void GameActionFightSpellCooldownVariationMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightSpellCooldownVariationMessage(param1);
}

void GameActionFightSpellCooldownVariationMessage::serializeAs_GameActionFightSpellCooldownVariationMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
    }
    else
    {
      param1->writeVarShort((int)this->spellId);
      param1->writeVarShort((int)this->value);
      return;
    }
  }
}

void GameActionFightSpellCooldownVariationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightSpellCooldownVariationMessage(param1);
}

void GameActionFightSpellCooldownVariationMessage::deserializeAs_GameActionFightSpellCooldownVariationMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightSpellCooldownVariationMessage.targetId.";
  }
  else
  {
    this->spellId = param1->readVarUhShort();
    if(this->spellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightSpellCooldownVariationMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightSpellCooldownVariationMessage.spellId.";
    }
    else
    {
      this->value = param1->readVarShort();
      return;
    }
  }
}

GameActionFightSpellCooldownVariationMessage::GameActionFightSpellCooldownVariationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTSPELLCOOLDOWNVARIATIONMESSAGE;
}

