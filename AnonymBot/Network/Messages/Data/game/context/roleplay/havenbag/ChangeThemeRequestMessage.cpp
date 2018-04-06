#include "ChangeThemeRequestMessage.h"

void ChangeThemeRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ChangeThemeRequestMessage(param1);
}

void ChangeThemeRequestMessage::serializeAs_ChangeThemeRequestMessage(Writer *param1)
{
  param1->writeByte(this->theme);
}

void ChangeThemeRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ChangeThemeRequestMessage(param1);
}

void ChangeThemeRequestMessage::deserializeAs_ChangeThemeRequestMessage(Reader *param1)
{
  this->theme = param1->readByte();
}

ChangeThemeRequestMessage::ChangeThemeRequestMessage()
{
  m_type = MessageEnum::CHANGETHEMEREQUESTMESSAGE;
}

