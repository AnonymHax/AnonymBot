#include "ChannelEnablingMessage.h"

void ChannelEnablingMessage::serialize(Writer *param1)
{
  this->serializeAs_ChannelEnablingMessage(param1);
}

void ChannelEnablingMessage::serializeAs_ChannelEnablingMessage(Writer *param1)
{
  param1->writeByte(this->channel);
  param1->writeBool(this->enable);
}

void ChannelEnablingMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChannelEnablingMessage(param1);
}

void ChannelEnablingMessage::deserializeAs_ChannelEnablingMessage(Reader *param1)
{
  this->channel = param1->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChannelEnablingMessage -"<<"Forbidden value (" << this->channel << ") on element of ChannelEnablingMessage.channel.";
  }
  else
  {
    this->enable = param1->readBool();
    return;
  }
}

ChannelEnablingMessage::ChannelEnablingMessage()
{
  m_type = MessageEnum::CHANNELENABLINGMESSAGE;
}

