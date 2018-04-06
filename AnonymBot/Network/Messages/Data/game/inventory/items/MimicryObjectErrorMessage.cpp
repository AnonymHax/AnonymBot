#include "MimicryObjectErrorMessage.h"

void MimicryObjectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_MimicryObjectErrorMessage(param1);
}

void MimicryObjectErrorMessage::serializeAs_MimicryObjectErrorMessage(Writer *param1)
{
  SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(param1);
  param1->writeBool(this->preview);
}

void MimicryObjectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MimicryObjectErrorMessage(param1);
}

void MimicryObjectErrorMessage::deserializeAs_MimicryObjectErrorMessage(Reader *param1)
{
  SymbioticObjectErrorMessage::deserialize(param1);
  this->preview = param1->readBool();
}

MimicryObjectErrorMessage::MimicryObjectErrorMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTERRORMESSAGE;
}

