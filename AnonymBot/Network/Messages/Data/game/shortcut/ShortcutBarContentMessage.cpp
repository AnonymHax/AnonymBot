#include "ShortcutBarContentMessage.h"

void ShortcutBarContentMessage::serialize(Writer *param1)
{
  this->serializeAs_ShortcutBarContentMessage(param1);
}

void ShortcutBarContentMessage::serializeAs_ShortcutBarContentMessage(Writer *param1)
{
  param1->writeByte(this->barType);
  param1->writeShort((short)this->shortcuts.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->shortcuts.size())
  {
    param1->writeShort((short)qSharedPointerCast<Shortcut>(this->shortcuts[_loc2_])->getTypes().last());
    qSharedPointerCast<Shortcut>(this->shortcuts[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void ShortcutBarContentMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ShortcutBarContentMessage(param1);
}

void ShortcutBarContentMessage::deserializeAs_ShortcutBarContentMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<Shortcut> _loc5_ ;
  this->barType = param1->readByte();
  if(this->barType < 0)
  {
    qDebug()<<"ERREUR - ShortcutBarContentMessage -"<<"Forbidden value (" << this->barType << ") on element of ShortcutBarContentMessage.barType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<Shortcut>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->shortcuts.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

ShortcutBarContentMessage::ShortcutBarContentMessage()
{
  m_type = MessageEnum::SHORTCUTBARCONTENTMESSAGE;
}

