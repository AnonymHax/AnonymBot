#include "MimicryObjectPreviewMessage.h"

void MimicryObjectPreviewMessage::serialize(Writer *param1)
{
  this->serializeAs_MimicryObjectPreviewMessage(param1);
}

void MimicryObjectPreviewMessage::serializeAs_MimicryObjectPreviewMessage(Writer *param1)
{
  this->result->serializeAs_ObjectItem(param1);
}

void MimicryObjectPreviewMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MimicryObjectPreviewMessage(param1);
}

void MimicryObjectPreviewMessage::deserializeAs_MimicryObjectPreviewMessage(Reader *param1)
{
  this->result = QSharedPointer<ObjectItem>(new ObjectItem() );
  this->result->deserialize(param1);
}

MimicryObjectPreviewMessage::MimicryObjectPreviewMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTPREVIEWMESSAGE;
}

