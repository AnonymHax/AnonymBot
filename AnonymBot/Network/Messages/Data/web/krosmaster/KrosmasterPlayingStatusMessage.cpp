#include "KrosmasterPlayingStatusMessage.h"

void KrosmasterPlayingStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_KrosmasterPlayingStatusMessage(param1);
}

void KrosmasterPlayingStatusMessage::serializeAs_KrosmasterPlayingStatusMessage(Writer *param1)
{
  param1->writeBool(this->playing);
}

void KrosmasterPlayingStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KrosmasterPlayingStatusMessage(param1);
}

void KrosmasterPlayingStatusMessage::deserializeAs_KrosmasterPlayingStatusMessage(Reader *param1)
{
  this->playing = param1->readBool();
}

KrosmasterPlayingStatusMessage::KrosmasterPlayingStatusMessage()
{
  m_type = MessageEnum::KROSMASTERPLAYINGSTATUSMESSAGE;
}

