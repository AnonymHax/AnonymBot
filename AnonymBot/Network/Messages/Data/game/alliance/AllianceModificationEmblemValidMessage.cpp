#include "AllianceModificationEmblemValidMessage.h"

void AllianceModificationEmblemValidMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceModificationEmblemValidMessage(param1);
}

void AllianceModificationEmblemValidMessage::serializeAs_AllianceModificationEmblemValidMessage(Writer *param1)
{
  this->Alliancemblem.serializeAs_GuildEmblem(param1);
}

void AllianceModificationEmblemValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceModificationEmblemValidMessage(param1);
}

void AllianceModificationEmblemValidMessage::deserializeAs_AllianceModificationEmblemValidMessage(Reader *param1)
{
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserialize(param1);
}

AllianceModificationEmblemValidMessage::AllianceModificationEmblemValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE;
}

