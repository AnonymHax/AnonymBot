#include "SymbioticObjectErrorMessage.h"

void SymbioticObjectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_SymbioticObjectErrorMessage(param1);
}

void SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(Writer *param1)
{
  ObjectErrorMessage::serializeAs_ObjectErrorMessage(param1);
  param1->writeByte(this->errorCode);
}

void SymbioticObjectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SymbioticObjectErrorMessage(param1);
}

void SymbioticObjectErrorMessage::deserializeAs_SymbioticObjectErrorMessage(Reader *param1)
{
  ObjectErrorMessage::deserialize(param1);
  this->errorCode = param1->readByte();
}

SymbioticObjectErrorMessage::SymbioticObjectErrorMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTERRORMESSAGE;
}

