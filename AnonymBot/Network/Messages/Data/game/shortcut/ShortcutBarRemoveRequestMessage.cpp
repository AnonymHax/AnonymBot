#include "ShortcutBarRemoveRequestMessage.h"

void ShortcutBarRemoveRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarRemoveRequestMessage(param1);
}

void ShortcutBarRemoveRequestMessage::serializeAs_ShortcutBarRemoveRequestMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  if(this->slot < 0 || this->slot > 99)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  else
  {
    param1->writeByte(this->slot);
    return;
  }
}

void ShortcutBarRemoveRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarRemoveRequestMessage(param1);
}

void ShortcutBarRemoveRequestMessage::deserializeAs_ShortcutBarRemoveRequestMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRemoveRequestMessage.barType.";
  }
  else
  {
    this->slot = param1->readByte();
    if(this->slot < 0 || this->slot > 99)
    {
      qDebug()<<"ERREUR - ShortcutBarRemoveRequestMessage -"<<"Forbidden value (" << this->slot << ") on element of ShortcutBarRemoveRequestMessage.slot.";
    }
    else
    {
      return;
    }
  }
}

ShortcutBarRemoveRequestMessage::ShortcutBarRemoveRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARREMOVEREQUESTMESSAGE;
}

