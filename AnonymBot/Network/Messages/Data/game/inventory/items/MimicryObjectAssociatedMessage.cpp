#include "MimicryObjectAssociatedMessage.h"

void MimicryObjectAssociatedMessage::serialize(Writer *param1)
{
  this->serializeAs_MimicryObjectAssociatedMessage(param1);
}

void MimicryObjectAssociatedMessage::serializeAs_MimicryObjectAssociatedMessage(Writer *param1)
{
  SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(param1);
}

void MimicryObjectAssociatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MimicryObjectAssociatedMessage(param1);
}

void MimicryObjectAssociatedMessage::deserializeAs_MimicryObjectAssociatedMessage(Reader *param1)
{
  SymbioticObjectAssociatedMessage::deserialize(param1);
}

MimicryObjectAssociatedMessage::MimicryObjectAssociatedMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTASSOCIATEDMESSAGE;
}

