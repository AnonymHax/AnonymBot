#include "GameActionFightCastOnTargetRequestMessage.h"

void GameActionFightCastOnTargetRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightCastOnTargetRequestMessage(param1);
}

void GameActionFightCastOnTargetRequestMessage::serializeAs_GameActionFightCastOnTargetRequestMessage(Writer *param1)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  else
  {
    param1->writeVarShort((int)this->spellId);
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeDouble(this->targetId);
      return;
    }
  }
}

void GameActionFightCastOnTargetRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightCastOnTargetRequestMessage(param1);
}

void GameActionFightCastOnTargetRequestMessage::deserializeAs_GameActionFightCastOnTargetRequestMessage(Reader *param1)
{
  this->spellId = param1->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->spellId << ") on element of GameActionFightCastOnTargetRequestMessage.spellId.";
  }
  else
  {
    this->targetId = param1->readDouble();
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameActionFightCastOnTargetRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightCastOnTargetRequestMessage.targetId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightCastOnTargetRequestMessage::GameActionFightCastOnTargetRequestMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTCASTONTARGETREQUESTMESSAGE;
}

