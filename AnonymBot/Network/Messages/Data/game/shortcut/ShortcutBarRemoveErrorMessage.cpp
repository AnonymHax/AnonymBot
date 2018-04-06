#include "ShortcutBarRemoveErrorMessage.h"

void ShortcutBarRemoveErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarRemoveErrorMessage(param1);
}

void ShortcutBarRemoveErrorMessage::serializeAs_ShortcutBarRemoveErrorMessage(Writer *param1)
{
  param1->writeByte(this->error);
}

void ShortcutBarRemoveErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarRemoveErrorMessage(param1);
}

void ShortcutBarRemoveErrorMessage::deserializeAs_ShortcutBarRemoveErrorMessage(Reader *param1)
{
  this->error = param1->readByte();
  if(this->error < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveErrorMessage -"<<"Forbidden value (" << this->error << ") on element of ShortcutBarRemoveErrorMessage.error.";
  }
  else
  {
    return;
  }
}

ShortcutBarRemoveErrorMessage::ShortcutBarRemoveErrorMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEERRORMESSAGE;
}

