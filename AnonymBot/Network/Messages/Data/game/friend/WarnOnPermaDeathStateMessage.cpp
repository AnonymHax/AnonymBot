#include "WarnOnPermaDeathStateMessage.h"

void WarnOnPermaDeathStateMessage::serialize(Writer *param1)
{
  this->serializeAs_WarnOnPermaDeathStateMessage(param1);
}

void WarnOnPermaDeathStateMessage::serializeAs_WarnOnPermaDeathStateMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void WarnOnPermaDeathStateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_WarnOnPermaDeathStateMessage(param1);
}

void WarnOnPermaDeathStateMessage::deserializeAs_WarnOnPermaDeathStateMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

WarnOnPermaDeathStateMessage::WarnOnPermaDeathStateMessage()
{
  m_type = MessageEnum::WARNONPERMADEATHSTATEMESSAGE;
}

