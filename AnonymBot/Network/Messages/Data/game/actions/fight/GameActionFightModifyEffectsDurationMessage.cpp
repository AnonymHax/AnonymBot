#include "GameActionFightModifyEffectsDurationMessage.h"

void GameActionFightModifyEffectsDurationMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightModifyEffectsDurationMessage(param1);
}

void GameActionFightModifyEffectsDurationMessage::serializeAs_GameActionFightModifyEffectsDurationMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightModifyEffectsDurationMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    param1->writeShort((short)this->delta);
    return;
  }
}

void GameActionFightModifyEffectsDurationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightModifyEffectsDurationMessage(param1);
}

void GameActionFightModifyEffectsDurationMessage::deserializeAs_GameActionFightModifyEffectsDurationMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightModifyEffectsDurationMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightModifyEffectsDurationMessage.targetId.";
  }
  else
  {
    this->delta = param1->readShort();
    return;
  }
}

GameActionFightModifyEffectsDurationMessage::GameActionFightModifyEffectsDurationMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTMODIFYEFFECTSDURATIONMESSAGE;
}

