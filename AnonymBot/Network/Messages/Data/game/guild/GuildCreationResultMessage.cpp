#include "GuildCreationResultMessage.h"

void GuildCreationResultMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildCreationResultMessage(param1);
}

void GuildCreationResultMessage::serializeAs_GuildCreationResultMessage(Writer *param1)
{
  param1->writeByte(this->result);
}

void GuildCreationResultMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildCreationResultMessage(param1);
}

void GuildCreationResultMessage::deserializeAs_GuildCreationResultMessage(Reader *param1)
{
  this->result = param1->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - GuildCreationResultMessage -"<<"Forbidden value (" << this->result << ") on element of GuildCreationResultMessage.result.";
  }
  else
  {
    return;
  }
}

GuildCreationResultMessage::GuildCreationResultMessage()
{
  m_type = MessageEnum::GUILDCREATIONRESULTMESSAGE;
}

