#include "SpouseStatusMessage.h"

void SpouseStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_SpouseStatusMessage(param1);
}

void SpouseStatusMessage::serializeAs_SpouseStatusMessage(Writer *param1)
{
  param1->writeBool(this->hasSpouse);
}

void SpouseStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SpouseStatusMessage(param1);
}

void SpouseStatusMessage::deserializeAs_SpouseStatusMessage(Reader *param1)
{
  this->hasSpouse = param1->readBool();
}

SpouseStatusMessage::SpouseStatusMessage()
{
  m_type = MessageEnum::SPOUSESTATUSMESSAGE;
}

