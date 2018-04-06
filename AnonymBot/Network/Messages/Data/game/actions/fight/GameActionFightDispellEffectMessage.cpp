#include "GameActionFightDispellEffectMessage.h"

void GameActionFightDispellEffectMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightDispellEffectMessage(param1);
}

void GameActionFightDispellEffectMessage::serializeAs_GameActionFightDispellEffectMessage(Writer *param1)
{
  GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(param1);
  if(this->boostUID < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellEffectMessage -"<<"Forbidden value (" << this->boostUID << ") on element boostUID.";
  }
  else
  {
    param1->writeInt((int)this->boostUID);
    return;
  }
}

void GameActionFightDispellEffectMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightDispellEffectMessage(param1);
}

void GameActionFightDispellEffectMessage::deserializeAs_GameActionFightDispellEffectMessage(Reader *param1)
{
  GameActionFightDispellMessage::deserialize(param1);
  this->boostUID = param1->readInt();
  if(this->boostUID < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellEffectMessage -"<<"Forbidden value (" << this->boostUID << ") on element of GameActionFightDispellEffectMessage.boostUID.";
  }
  else
  {
    return;
  }
}

GameActionFightDispellEffectMessage::GameActionFightDispellEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLEFFECTMESSAGE;
}

