#include "GuildGetInformationsMessage.h"

void GuildGetInformationsMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildGetInformationsMessage(param1);
}

void GuildGetInformationsMessage::serializeAs_GuildGetInformationsMessage(Writer *param1)
{
  param1->writeByte(this->infoType);
}

void GuildGetInformationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildGetInformationsMessage(param1);
}

void GuildGetInformationsMessage::deserializeAs_GuildGetInformationsMessage(Reader *param1)
{
  this->infoType = param1->readByte();
  if(this->infoType < 0)
  {
    qDebug()<<"ERREUR - GuildGetInformationsMessage -"<<"Forbidden value (" << this->infoType << ") on element of GuildGetInformationsMessage.infoType.";
  }
  else
  {
    return;
  }
}

GuildGetInformationsMessage::GuildGetInformationsMessage()
{
  m_type = MessageEnum::GUILDGETINFORMATIONSMESSAGE;
}

