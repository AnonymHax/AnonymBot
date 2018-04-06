#include "GuildFightPlayersHelpersLeaveMessage.h"

void GuildFightPlayersHelpersLeaveMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightPlayersHelpersLeaveMessage(param1);
}

void GuildFightPlayersHelpersLeaveMessage::serializeAs_GuildFightPlayersHelpersLeaveMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
    }
    else
    {
      param1->writeVarLong((double)this->playerId);
      return;
    }
  }
}

void GuildFightPlayersHelpersLeaveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightPlayersHelpersLeaveMessage(param1);
}

void GuildFightPlayersHelpersLeaveMessage::deserializeAs_GuildFightPlayersHelpersLeaveMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersHelpersLeaveMessage.fightId.";
  }
  else
  {
    this->playerId = param1->readVarUhLong();
    if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildFightPlayersHelpersLeaveMessage -"<<"Forbidden value (" << this->playerId << ") on element of GuildFightPlayersHelpersLeaveMessage.playerId.";
    }
    else
    {
      return;
    }
  }
}

GuildFightPlayersHelpersLeaveMessage::GuildFightPlayersHelpersLeaveMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE;
}

