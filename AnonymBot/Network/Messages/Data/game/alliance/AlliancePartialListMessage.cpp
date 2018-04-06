#include "AlliancePartialListMessage.h"

void AlliancePartialListMessage::serialize(Writer *param1)
{
  this->serializeAs_AlliancePartialListMessage(param1);
}

void AlliancePartialListMessage::serializeAs_AlliancePartialListMessage(Writer *param1)
{
  AllianceListMessage::serializeAs_AllianceListMessage(param1);
}

void AlliancePartialListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AlliancePartialListMessage(param1);
}

void AlliancePartialListMessage::deserializeAs_AlliancePartialListMessage(Reader *param1)
{
  AllianceListMessage::deserialize(param1);
}

AlliancePartialListMessage::AlliancePartialListMessage()
{
  m_type = MessageEnum::ALLIANCEPARTIALLISTMESSAGE;
}

