#include "ShortcutBarAddRequestMessage.h"

void ShortcutBarAddRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarAddRequestMessage(param1);
}

void ShortcutBarAddRequestMessage::serializeAs_ShortcutBarAddRequestMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  param1->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(param1);
}

void ShortcutBarAddRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarAddRequestMessage(param1);
}

void ShortcutBarAddRequestMessage::deserializeAs_ShortcutBarAddRequestMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarAddRequestMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarAddRequestMessage.barType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_loc2_));
    this->shortcut->deserialize(param1);
    return;
  }
}

ShortcutBarAddRequestMessage::ShortcutBarAddRequestMessage()
{
  m_type = MessageEnum::SHORTCUTBARADDREQUESTMESSAGE;
}

