#include "ShortcutBarRemovedMessage.h"

void ShortcutBarRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarRemovedMessage(param1);
}

void ShortcutBarRemovedMessage::serializeAs_ShortcutBarRemovedMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  else
  {
    param1->writeByte(this->slot);
    return;
  }
}

void ShortcutBarRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarRemovedMessage(param1);
}

void ShortcutBarRemovedMessage::deserializeAs_ShortcutBarRemovedMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRemovedMessage.barType.";
  }
  else
  {
    this->slot = param1->readByte();
    if(this->slot < 0 || this->slot > 99)
    {
      qDebug()<<"ERREUR - ShortcutBarRemovedMessage -"<<"Forbidden value (" << this->slot << ") on element of ShortcutBarRemovedMessage.slot.";
    }
    else
    {
      return;
    }
  }
}

ShortcutBarRemovedMessage::ShortcutBarRemovedMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEDMESSAGE;
}

