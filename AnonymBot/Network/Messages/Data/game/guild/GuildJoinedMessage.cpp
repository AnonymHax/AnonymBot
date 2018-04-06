#include "GuildJoinedMessage.h"

void GuildJoinedMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildJoinedMessage(param1);
}

void GuildJoinedMessage::serializeAs_GuildJoinedMessage(Writer *param1)
{
  this->guildInfo->serializeAs_GuildInformations(param1);
  if(this->memberRights < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->memberRights << ") on element memberRights.";
  }
  else
  {
    param1->writeVarInt((int)this->memberRights);
    return;
  }
}

void GuildJoinedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildJoinedMessage(param1);
}

void GuildJoinedMessage::deserializeAs_GuildJoinedMessage(Reader *param1)
{
  this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
  this->guildInfo->deserialize(param1);
  this->memberRights = param1->readVarUhInt();
  if(this->memberRights < 0)
  {
    qDebug()<<"ERREUR - GuildJoinedMessage -"<<"Forbidden value (" << this->memberRights << ") on element of GuildJoinedMessage.memberRights.";
  }
  else
  {
    return;
  }
}

GuildJoinedMessage::GuildJoinedMessage()
{
  m_type = MessageEnum::GUILDJOINEDMESSAGE;
}

