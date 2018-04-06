#include "ArenaFighterLeaveMessage.h"

void ArenaFighterLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_ArenaFighterLeaveMessage(param1);
}

void ArenaFighterLeaveMessage::serializeAs_ArenaFighterLeaveMessage(Writer *param1)
{
  this->leaver.serializeAs_CharacterBasicMinimalInformations(param1);
}

void ArenaFighterLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ArenaFighterLeaveMessage(param1);
}

void ArenaFighterLeaveMessage::deserializeAs_ArenaFighterLeaveMessage(Reader *param1)
{
  this->leaver = CharacterBasicMinimalInformations();
  this->leaver.deserialize(param1);
}

ArenaFighterLeaveMessage::ArenaFighterLeaveMessage()
{
  m_type = MessageEnum::ARENAFIGHTERLEAVEMESSAGE;
}

