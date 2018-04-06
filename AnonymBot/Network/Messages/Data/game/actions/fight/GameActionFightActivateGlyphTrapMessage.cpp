#include "GameActionFightActivateGlyphTrapMessage.h"

void GameActionFightActivateGlyphTrapMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightActivateGlyphTrapMessage(param1);
}

void GameActionFightActivateGlyphTrapMessage::serializeAs_GameActionFightActivateGlyphTrapMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->markId);
  param1->writeBool(this->active);
}

void GameActionFightActivateGlyphTrapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightActivateGlyphTrapMessage(param1);
}

void GameActionFightActivateGlyphTrapMessage::deserializeAs_GameActionFightActivateGlyphTrapMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->markId = param1->readShort();
  this->active = param1->readBool();
}

GameActionFightActivateGlyphTrapMessage::GameActionFightActivateGlyphTrapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTACTIVATEGLYPHTRAPMESSAGE;
}

