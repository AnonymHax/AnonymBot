#include "AtlasPointInformationsMessage.h"

void AtlasPointInformationsMessage::serialize(Writer *param1)
{
  this->serializeAs_AtlasPointInformationsMessage(param1);
}

void AtlasPointInformationsMessage::serializeAs_AtlasPointInformationsMessage(Writer *param1)
{
  this->type->serializeAs_AtlasPointsInformations(param1);
}

void AtlasPointInformationsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AtlasPointInformationsMessage(param1);
}

void AtlasPointInformationsMessage::deserializeAs_AtlasPointInformationsMessage(Reader *param1)
{
  this->type = QSharedPointer<AtlasPointsInformations>(new AtlasPointsInformations() );
  this->type->deserialize(param1);
}

AtlasPointInformationsMessage::AtlasPointInformationsMessage()
{
  m_type = MessageEnum::ATLASPOINTINFORMATIONSMESSAGE;
}

