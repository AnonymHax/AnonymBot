#include "GameActionFightDispellableEffectMessage.h"

void GameActionFightDispellableEffectMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDispellableEffectMessage(param1);
}

void GameActionFightDispellableEffectMessage::serializeAs_GameActionFightDispellableEffectMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  param1->writeShort((short)this->effect->getTypes().last());
  this->effect->serialize(param1);
}

void GameActionFightDispellableEffectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDispellableEffectMessage(param1);
}

void GameActionFightDispellableEffectMessage::deserializeAs_GameActionFightDispellableEffectMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_loc2_));
  this->effect->deserialize(param1);
}

GameActionFightDispellableEffectMessage::GameActionFightDispellableEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLABLEEFFECTMESSAGE;
}

