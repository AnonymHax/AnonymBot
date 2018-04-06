#include "GuildFightPlayersEnemyRemoveMessage.h"

void GuildFightPlayersEnemyRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightPlayersEnemyRemoveMessage(param1);
}

void GuildFightPlayersEnemyRemoveMessage::serializeAs_GuildFightPlayersEnemyRemoveMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      return;
    }
  }
}

void GuildFightPlayersEnemyRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightPlayersEnemyRemoveMessage(param1);
}

void GuildFightPlayersEnemyRemoveMessage::deserializeAs_GuildFightPlayersEnemyRemoveMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersEnemyRemoveMessage.fightId.";
  }
  else
  {
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightPlayersEnemyRemoveMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildFightPlayersEnemyRemoveMessage.playerId.";
    }
    else
    {
      return;
    }
  }
}

GuildFightPlayersEnemyRemoveMessage::GuildFightPlayersEnemyRemoveMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSENEMYREMOVEMESSAGE;
}

