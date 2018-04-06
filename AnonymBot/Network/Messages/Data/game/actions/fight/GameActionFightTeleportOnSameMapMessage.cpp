#include "GameActionFightTeleportOnSameMapMessage.h"

void GameActionFightTeleportOnSameMapMessage::serialize(Writer *param1)
{
  this->serializeAs_GameActionFightTeleportOnSameMapMessage(param1);
}

void GameActionFightTeleportOnSameMapMessage::serializeAs_GameActionFightTeleportOnSameMapMessage(Writer *param1)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(param1);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
    }
    else
    {
      param1->writeShort((short)this->cellId);
      return;
    }
  }
}

void GameActionFightTeleportOnSameMapMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameActionFightTeleportOnSameMapMessage(param1);
}

void GameActionFightTeleportOnSameMapMessage::deserializeAs_GameActionFightTeleportOnSameMapMessage(Reader *param1)
{
  AbstractGameActionMessage::deserialize(param1);
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameActionFightTeleportOnSameMapMessage.targetId.";
  }
  else
  {
    this->cellId = param1->readShort();
    if(this->cellId < -1 || this->cellId > 559)
    {
      qDebug()<<"ERREUR - GameActionFightTeleportOnSameMapMessage -"<<"Forbidden value (" << this->cellId << ") on element of GameActionFightTeleportOnSameMapMessage.cellId.";
    }
    else
    {
      return;
    }
  }
}

GameActionFightTeleportOnSameMapMessage::GameActionFightTeleportOnSameMapMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTELEPORTONSAMEMAPMESSAGE;
}

