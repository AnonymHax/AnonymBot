#include "AreaFightModificatorUpdateMessage.h"

void AreaFightModificatorUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_AreaFightModificatorUpdateMessage(param1);
}

void AreaFightModificatorUpdateMessage::serializeAs_AreaFightModificatorUpdateMessage(Writer *param1)
{
  param1->writeInt((int)this->spellPairId);
}

void AreaFightModificatorUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AreaFightModificatorUpdateMessage(param1);
}

void AreaFightModificatorUpdateMessage::deserializeAs_AreaFightModificatorUpdateMessage(Reader *param1)
{
  this->spellPairId = param1->readInt();
}

AreaFightModificatorUpdateMessage::AreaFightModificatorUpdateMessage()
{
  m_type = MessageEnum::AREAFIGHTMODIFICATORUPDATEMESSAGE;
}

