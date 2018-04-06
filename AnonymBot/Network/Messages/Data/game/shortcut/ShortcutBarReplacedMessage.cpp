#include "ShortcutBarReplacedMessage.h"

void ShortcutBarReplacedMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarReplacedMessage(param1);
}

void ShortcutBarReplacedMessage::serializeAs_ShortcutBarReplacedMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  param1->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(param1);
}

void ShortcutBarReplacedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarReplacedMessage(param1);
}

void ShortcutBarReplacedMessage::deserializeAs_ShortcutBarReplacedMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarReplacedMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarReplacedMessage.barType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_loc2_));
    this->shortcut->deserialize(param1);
    return;
  }
}

ShortcutBarReplacedMessage::ShortcutBarReplacedMessage()
{
  m_type = MessageEnum::SHORTCUTBARREPLACEDMESSAGE;
}

