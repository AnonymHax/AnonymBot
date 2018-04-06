#include "GameContextKickMessage.h"

void GameContextKickMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextKickMessage(param1);
}

void GameContextKickMessage::serializeAs_GameContextKickMessage(Writer *param1)
{
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextKickMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeDouble(this->targetId);
    return;
  }
}

void GameContextKickMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextKickMessage(param1);
}

void GameContextKickMessage::deserializeAs_GameContextKickMessage(Reader *param1)
{
  this->targetId = param1->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextKickMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameContextKickMessage.targetId.";
  }
  else
  {
    return;
  }
}

GameContextKickMessage::GameContextKickMessage()
{
  m_type = MessageEnum::GAMECONTEXTKICKMESSAGE;
}

