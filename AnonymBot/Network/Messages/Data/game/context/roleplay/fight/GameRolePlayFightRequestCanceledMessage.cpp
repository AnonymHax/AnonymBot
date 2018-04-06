#include "GameRolePlayFightRequestCanceledMessage.h"

void GameRolePlayFightRequestCanceledMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayFightRequestCanceledMessage(param1);
}

void GameRolePlayFightRequestCanceledMessage::serializeAs_GameRolePlayFightRequestCanceledMessage(Writer *param1)
{
  param1->writeInt((int)this->fightId);
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
  }
  else
  {
    param1->writeDouble(this->sourceId);
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeDouble(this->targetId);
      return;
    }
  }
}

void GameRolePlayFightRequestCanceledMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayFightRequestCanceledMessage(param1);
}

void GameRolePlayFightRequestCanceledMessage::deserializeAs_GameRolePlayFightRequestCanceledMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  this->sourceId = param1->readDouble();
  if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->sourceId << ") on element of GameRolePlayFightRequestCanceledMessage.sourceId.";
  }
  else
  {
    this->targetId = param1->readDouble();
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameRolePlayFightRequestCanceledMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayFightRequestCanceledMessage.targetId.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayFightRequestCanceledMessage::GameRolePlayFightRequestCanceledMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYFIGHTREQUESTCANCELEDMESSAGE;
}

