#include "IdolsPresetUpdateMessage.h"

void IdolsPresetUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolsPresetUpdateMessage(param1);
}

void IdolsPresetUpdateMessage::serializeAs_IdolsPresetUpdateMessage(Writer *param1)
{
  this->idolsPreset.serializeAs_IdolsPreset(param1);
}

void IdolsPresetUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolsPresetUpdateMessage(param1);
}

void IdolsPresetUpdateMessage::deserializeAs_IdolsPresetUpdateMessage(Reader *param1)
{
  this->idolsPreset = IdolsPreset();
  this->idolsPreset.deserialize(param1);
}

IdolsPresetUpdateMessage::IdolsPresetUpdateMessage()
{
  m_type = MessageEnum::IDOLSPRESETUPDATEMESSAGE;
}

