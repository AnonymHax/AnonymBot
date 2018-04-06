#include "WarnOnPermaDeathMessage.h"

void WarnOnPermaDeathMessage::serialize(Writer *param1)
{
  this->serializeAs_WarnOnPermaDeathMessage(param1);
}

void WarnOnPermaDeathMessage::serializeAs_WarnOnPermaDeathMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void WarnOnPermaDeathMessage::deserialize(Reader *param1)
{
  this->deserializeAs_WarnOnPermaDeathMessage(param1);
}

void WarnOnPermaDeathMessage::deserializeAs_WarnOnPermaDeathMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

WarnOnPermaDeathMessage::WarnOnPermaDeathMessage()
{
  m_type = MessageEnum::WARNONPERMADEATHMESSAGE;
}

