#include "ShortcutBarRefreshMessage.h"

void ShortcutBarRefreshMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarRefreshMessage(param1);
}

void ShortcutBarRefreshMessage::serializeAs_ShortcutBarRefreshMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  param1->writeShort((short)this->shortcut->getTypes().last());
  this->shortcut->serialize(param1);
}

void ShortcutBarRefreshMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarRefreshMessage(param1);
}

void ShortcutBarRefreshMessage::deserializeAs_ShortcutBarRefreshMessage(Reader *param1)
{
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarRefreshMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarRefreshMessage.barType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    this->shortcut = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_loc2_));
    this->shortcut->deserialize(param1);
    return;
  }
}

ShortcutBarRefreshMessage::ShortcutBarRefreshMessage()
{
  m_type = MessageEnum::SHORTCUTBARREFRESHMESSAGE;
}

