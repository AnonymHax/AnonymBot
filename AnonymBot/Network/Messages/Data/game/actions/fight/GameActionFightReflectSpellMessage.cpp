#include "GameActionFightReflectSpellMessage.h"

void GameActionFightReflectSpellMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightReflectSpellMessage(param1);
}

void GameActionFightReflectSpellMessage::serializeAs_GameActionFightReflectSpellMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReflectSpellMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameActionFightReflectSpellMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightReflectSpellMessage(param1);
}

void GameActionFightReflectSpellMessage::deserializeAs_GameActionFightReflectSpellMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightReflectSpellMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightReflectSpellMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameActionFightReflectSpellMessage::GameActionFightReflectSpellMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTREFLECTSPELLMESSAGE;
}

