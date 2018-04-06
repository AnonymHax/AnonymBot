#include "ChannelEnablingChangeMessage.h"

void ChannelEnablingChangeMessage::serialize(Writer *param1)
{
  this->serializeAs_ChannelEnablingChangeMessage(param1);
}

void ChannelEnablingChangeMessage::serializeAs_ChannelEnablingChangeMessage(Writer *param1)
{
  param1->writeByte(this->channel);
  param1->writeBool(this->enable);
}

void ChannelEnablingChangeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChannelEnablingChangeMessage(param1);
}

void ChannelEnablingChangeMessage::deserializeAs_ChannelEnablingChangeMessage(Reader *param1)
{
  this->channel = param1->readByte();
  if(this->channel < 0)
  {
    qDebug()<<"ERREUR - ChannelEnablingChangeMessage -"<<"Forbidden value (" << this->channel << ") on element of ChannelEnablingChangeMessage.channel.";
  }
  else
  {
    this->enable = param1->readBool();
    return;
  }
}

ChannelEnablingChangeMessage::ChannelEnablingChangeMessage()
{
  m_type = MessageEnum::CHANNELENABLINGCHANGEMESSAGE;
}

