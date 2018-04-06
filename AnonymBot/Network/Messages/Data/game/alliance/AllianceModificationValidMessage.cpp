#include "AllianceModificationValidMessage.h"

void AllianceModificationValidMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceModificationValidMessage(param1);
}

void AllianceModificationValidMessage::serializeAs_AllianceModificationValidMessage(Writer *param1)
{
  param1->writeUTF(this->allianceName);
  param1->writeUTF(this->allianceTag);
  this->Alliancemblem.serializeAs_GuildEmblem(param1);
}

void AllianceModificationValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceModificationValidMessage(param1);
}

void AllianceModificationValidMessage::deserializeAs_AllianceModificationValidMessage(Reader *param1)
{
  this->allianceName = param1->readUTF();
  this->allianceTag = param1->readUTF();
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserialize(param1);
}

AllianceModificationValidMessage::AllianceModificationValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONVALIDMESSAGE;
}

