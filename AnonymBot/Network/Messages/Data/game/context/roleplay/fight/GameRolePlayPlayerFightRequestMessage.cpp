#include "GameRolePlayPlayerFightRequestMessage.h"

void GameRolePlayPlayerFightRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayPlayerFightRequestMessage(param1);
}

void GameRolePlayPlayerFightRequestMessage::serializeAs_GameRolePlayPlayerFightRequestMessage(Writer *param1)
{
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  else
  {
    param1->writeVarLong((double)this->targetId);
    if(this->targetCellId < -1 || this->targetCellId > 559)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetCellId << ") on element targetCellId.";
    }
    else
    {
      param1->writeShort((short)this->targetCellId);
      param1->writeBool(this->friendly);
      return;
    }
  }
}

void GameRolePlayPlayerFightRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayPlayerFightRequestMessage(param1);
}

void GameRolePlayPlayerFightRequestMessage::deserializeAs_GameRolePlayPlayerFightRequestMessage(Reader *param1)
{
  this->targetId = param1->readVarUhLong();
  if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of GameRolePlayPlayerFightRequestMessage.targetId.";
  }
  else
  {
    this->targetCellId = param1->readShort();
    if(this->targetCellId < -1 || this->targetCellId > 559)
    {
      qDebug()<<"ERREUR - GameRolePlayPlayerFightRequestMessage -"<<"Forbidden value (" << this->targetCellId << ") on element of GameRolePlayPlayerFightRequestMessage.targetCellId.";
    }
    else
    {
      this->friendly = param1->readBool();
      return;
    }
  }
}

GameRolePlayPlayerFightRequestMessage::GameRolePlayPlayerFightRequestMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYPLAYERFIGHTREQUESTMESSAGE;
  m_needsHash = true;
}

