#include "AllianceBulletinMessage.h"

void AllianceBulletinMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceBulletinMessage(param1);
}

void AllianceBulletinMessage::serializeAs_AllianceBulletinMessage(Writer *param1)
{
  BulletinMessage::serializeAs_BulletinMessage(param1);
}

void AllianceBulletinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceBulletinMessage(param1);
}

void AllianceBulletinMessage::deserializeAs_AllianceBulletinMessage(Reader *param1)
{
  BulletinMessage::deserialize(param1);
}

AllianceBulletinMessage::AllianceBulletinMessage()
{
  m_type = MessageEnum::ALLIANCEBULLETINMESSAGE;
}

