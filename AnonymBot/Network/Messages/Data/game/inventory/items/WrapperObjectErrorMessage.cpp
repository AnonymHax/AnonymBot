#include "WrapperObjectErrorMessage.h"

void WrapperObjectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_WrapperObjectErrorMessage(param1);
}

void WrapperObjectErrorMessage::serializeAs_WrapperObjectErrorMessage(Writer *param1)
{
  SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(param1);
}

void WrapperObjectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_WrapperObjectErrorMessage(param1);
}

void WrapperObjectErrorMessage::deserializeAs_WrapperObjectErrorMessage(Reader *param1)
{
  SymbioticObjectErrorMessage::deserialize(param1);
}

WrapperObjectErrorMessage::WrapperObjectErrorMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTERRORMESSAGE;
}

