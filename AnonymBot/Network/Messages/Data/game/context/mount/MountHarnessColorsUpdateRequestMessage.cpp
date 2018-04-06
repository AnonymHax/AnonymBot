#include "MountHarnessColorsUpdateRequestMessage.h"

void MountHarnessColorsUpdateRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountHarnessColorsUpdateRequestMessage(param1);
}

void MountHarnessColorsUpdateRequestMessage::serializeAs_MountHarnessColorsUpdateRequestMessage(Writer *param1)
{
  param1->writeBool(this->useHarnessColors);
}

void MountHarnessColorsUpdateRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountHarnessColorsUpdateRequestMessage(param1);
}

void MountHarnessColorsUpdateRequestMessage::deserializeAs_MountHarnessColorsUpdateRequestMessage(Reader *param1)
{
  this->useHarnessColors = param1->readBool();
}

MountHarnessColorsUpdateRequestMessage::MountHarnessColorsUpdateRequestMessage()
{
  m_type = MessageEnum::MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE;
}

