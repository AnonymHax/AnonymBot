#include "AllianceModificationNameAndTagValidMessage.h"

void AllianceModificationNameAndTagValidMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceModificationNameAndTagValidMessage(param1);
}

void AllianceModificationNameAndTagValidMessage::serializeAs_AllianceModificationNameAndTagValidMessage(Writer *param1)
{
  param1->writeUTF(this->allianceName);
  param1->writeUTF(this->allianceTag);
}

void AllianceModificationNameAndTagValidMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceModificationNameAndTagValidMessage(param1);
}

void AllianceModificationNameAndTagValidMessage::deserializeAs_AllianceModificationNameAndTagValidMessage(Reader *param1)
{
  this->allianceName = param1->readUTF();
  this->allianceTag = param1->readUTF();
}

AllianceModificationNameAndTagValidMessage::AllianceModificationNameAndTagValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONNAMEANDTAGVALIDMESSAGE;
}

