#include "GameActionFightTriggerEffectMessage.h"

void GameActionFightTriggerEffectMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightTriggerEffectMessage(param1);
}

void GameActionFightTriggerEffectMessage::serializeAs_GameActionFightTriggerEffectMessage(Writer *param1)
{
  GameActionFightDispellEffectMessage::serializeAs_GameActionFightDispellEffectMessage(param1);
}

void GameActionFightTriggerEffectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightTriggerEffectMessage(param1);
}

void GameActionFightTriggerEffectMessage::deserializeAs_GameActionFightTriggerEffectMessage(Reader *param1)
{
  GameActionFightDispellEffectMessage::deserialize(param1);
}

GameActionFightTriggerEffectMessage::GameActionFightTriggerEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE;
}

