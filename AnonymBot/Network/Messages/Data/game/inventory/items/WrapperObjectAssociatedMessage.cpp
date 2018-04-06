#include "WrapperObjectAssociatedMessage.h"

void WrapperObjectAssociatedMessage::serialize(Writer *param1)
{
  this->serializeAs_WrapperObjectAssociatedMessage(param1);
}

void WrapperObjectAssociatedMessage::serializeAs_WrapperObjectAssociatedMessage(Writer *param1)
{
  SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(param1);
}

void WrapperObjectAssociatedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_WrapperObjectAssociatedMessage(param1);
}

void WrapperObjectAssociatedMessage::deserializeAs_WrapperObjectAssociatedMessage(Reader *param1)
{
  SymbioticObjectAssociatedMessage::deserialize(param1);
}

WrapperObjectAssociatedMessage::WrapperObjectAssociatedMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTASSOCIATEDMESSAGE;
}

