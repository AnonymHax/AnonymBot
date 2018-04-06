#include "AccessoryPreviewMessage.h"

void AccessoryPreviewMessage::serialize(Writer *param1)
{
  this->serializeAs_AccessoryPreviewMessage(param1);
}

void AccessoryPreviewMessage::serializeAs_AccessoryPreviewMessage(Writer *param1)
{
  this->look->serializeAs_EntityLook(param1);
}

void AccessoryPreviewMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccessoryPreviewMessage(param1);
}

void AccessoryPreviewMessage::deserializeAs_AccessoryPreviewMessage(Reader *param1)
{
  this->look = QSharedPointer<EntityLook>(new EntityLook() );
  this->look->deserialize(param1);
}

AccessoryPreviewMessage::AccessoryPreviewMessage()
{
  m_type = MessageEnum::ACCESSORYPREVIEWMESSAGE;
}

