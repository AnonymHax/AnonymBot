#include "ShortcutBarAddErrorMessage.h"

void ShortcutBarAddErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarAddErrorMessage(param1);
}

void ShortcutBarAddErrorMessage::serializeAs_ShortcutBarAddErrorMessage(Writer *param1)
{
  param1->writeByte(this->error);
}

void ShortcutBarAddErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarAddErrorMessage(param1);
}

void ShortcutBarAddErrorMessage::deserializeAs_ShortcutBarAddErrorMessage(Reader *param1)
{
  this->error = param1->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarAddErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarAddErrorMessage.error.";
  }
  else
  {
    return;
  }
}

ShortcutBarAddErrorMessage::ShortcutBarAddErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARADDERRORMESSAGE;
}

