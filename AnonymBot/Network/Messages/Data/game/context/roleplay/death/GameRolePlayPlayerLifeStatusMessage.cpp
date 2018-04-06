#include "GameRolePlayPlayerLifeStatusMessage.h"

void GameRolePlayPlayerLifeStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPlayerLifeStatusMessage(param1);
}

void GameRolePlayPlayerLifeStatusMessage::serializeAs_GameRolePlayPlayerLifeStatusMessage(Writer *param1)
{
  param1->writeByte(this->state);
  if(this->phenixMapId < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->phenixMapId << ") on element phenixMapId.";
  }
  else
  {
    param1->writeInt((int)this->phenixMapId);
    return;
  }
}

void GameRolePlayPlayerLifeStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPlayerLifeStatusMessage(param1);
}

void GameRolePlayPlayerLifeStatusMessage::deserializeAs_GameRolePlayPlayerLifeStatusMessage(Reader *param1)
{
  this->state = param1->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->state << ") on element of GameRolePlayPlayerLifeStatusMessage.state.";
  }
  else
  {
    this->phenixMapId = param1->readInt();
    if(this->phenixMapId < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerLifeStatusMessage -"<<"Forbidden value (" << this->phenixMapId << ") on element of GameRolePlayPlayerLifeStatusMessage.phenixMapId.";
    }
    else
    {
      return;
    }
  }
}

GameRolePlayPlayerLifeStatusMessage::GameRolePlayPlayerLifeStatusMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE;
}

