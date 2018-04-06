#include "GuildModificationStartedMessage.h"

void GuildModificationStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildModificationStartedMessage(param1);
}

void GuildModificationStartedMessage::serializeAs_GuildModificationStartedMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->canChangeName);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->canChangeEmblem);
  param1->writeByte(_loc2_);
}

void GuildModificationStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildModificationStartedMessage(param1);
}

void GuildModificationStartedMessage::deserializeAs_GuildModificationStartedMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->canChangeName = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->canChangeEmblem = BooleanByteWrapper::getFlag(_loc2_, 1);
}

GuildModificationStartedMessage::GuildModificationStartedMessage()
{
  m_type = MessageEnum::GUILDMODIFICATIONSTARTEDMESSAGE;
}

