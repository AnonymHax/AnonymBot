#include "GameActionFightTriggerGlyphTrapMessage.h"

void GameActionFightTriggerGlyphTrapMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightTriggerGlyphTrapMessage(param1);
}

void GameActionFightTriggerGlyphTrapMessage::serializeAs_GameActionFightTriggerGlyphTrapMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->markId);
  if(this->triggeringCharacterId < -9.007199254740992E15 || this->triggeringCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeringCharacterId << ") on element triggeringCharacterId.";
  }
  else
  {
    param1->writeDouble(this->triggeringCharacterId);
    if(this->triggeredSpellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeredSpellId << ") on element triggeredSpellId.";
    }
    else
    {
      param1->writeVarShort((int)this->triggeredSpellId);
      return;
    }
  }
}

void GameActionFightTriggerGlyphTrapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightTriggerGlyphTrapMessage(param1);
}

void GameActionFightTriggerGlyphTrapMessage::deserializeAs_GameActionFightTriggerGlyphTrapMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->markId = param1->readShort();
  this->triggeringCharacterId = param1->readDouble();
  if(this->triggeringCharacterId < -9.007199254740992E15 || this->triggeringCharacterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeringCharacterId << ") on element of GameActionFightTriggerGlyphTrapMessage.triggeringCharacterId.";
  }
  else
  {
    this->triggeredSpellId = param1->readVarUhShort();
    if(this->triggeredSpellId < 0)
    {
      qDebug()<<"ERREUR - GameActionFightTriggerGlyphTrapMessage -"<<"Forbidden value (" << this->triggeredSpellId << ") on element of GameActionFightTriggerGlyphTrapMessage.triggeredSpellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightTriggerGlyphTrapMessage::GameActionFightTriggerGlyphTrapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTRIGGERGLYPHTRAPMESSAGE;
}

