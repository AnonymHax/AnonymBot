#include "AllianceCreationValidMessage.h"

void AllianceCreationValidMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceCreationValidMessage(param1);
}

void AllianceCreationValidMessage::serializeAs_AllianceCreationValidMessage(Writer *param1)
{
  param1->writeUTF(this->allianceName);
  param1->writeUTF(this->allianceTag);
  this->allianceEmblem.serializeAs_GuildEmblem(param1);
}

void AllianceCreationValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceCreationValidMessage(param1);
}

void AllianceCreationValidMessage::deserializeAs_AllianceCreationValidMessage(Reader *param1)
{
  this->allianceName = param1->readUTF();
  this->allianceTag = param1->readUTF();
  this->allianceEmblem = GuildEmblem();
  this->allianceEmblem.deserialize(param1);
}

AllianceCreationValidMessage::AllianceCreationValidMessage()
{
  m_type = MessageEnum::ALLIANCECREATIONVALIDMESSAGE;
}

