#include "GuildKickRequestMessage.h"

void GuildKickRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildKickRequestMessage(param1);
}

void GuildKickRequestMessage::serializeAs_GuildKickRequestMessage(Writer *param1)
{
  if(this->kickedId < 0 || this->kickedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element kickedId.";
  }
  else
  {
    param1->writeVarLong((double)this->kickedId);
    return;
  }
}

void GuildKickRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildKickRequestMessage(param1);
}

void GuildKickRequestMessage::deserializeAs_GuildKickRequestMessage(Reader *param1)
{
  this->kickedId = param1->readVarUhLong();
  if(this->kickedId < 0 || this->kickedId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element of GuildKickRequestMessage.kickedId.";
  }
  else
  {
    return;
  }
}

GuildKickRequestMessage::GuildKickRequestMessage()
{
  m_type = MessageEnum::GUILDKICKREQUESTMESSAGE;
}

