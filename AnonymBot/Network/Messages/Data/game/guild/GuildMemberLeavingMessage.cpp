#include "GuildMemberLeavingMessage.h"

void GuildMemberLeavingMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildMemberLeavingMessage(param1);
}

void GuildMemberLeavingMessage::serializeAs_GuildMemberLeavingMessage(Writer *param1)
{
  param1->writeBool(this->kicked);
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
  }
  else
  {
    param1->writeVarLong((double)this->memberId);
    return;
  }
}

void GuildMemberLeavingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMemberLeavingMessage(param1);
}

void GuildMemberLeavingMessage::deserializeAs_GuildMemberLeavingMessage(Reader *param1)
{
  this->kicked = param1->readBool();
  this->memberId = param1->readVarUhLong();
  if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildMemberLeavingMessage -"<<"Forbidden value (" << this->memberId << ") on element of GuildMemberLeavingMessage.memberId.";
  }
  else
  {
    return;
  }
}

GuildMemberLeavingMessage::GuildMemberLeavingMessage()
{
  m_type = MessageEnum::GUILDMEMBERLEAVINGMESSAGE;
}

