#include "GuildVersatileInfoListMessage.h"

void GuildVersatileInfoListMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildVersatileInfoListMessage(param1);
}

void GuildVersatileInfoListMessage::serializeAs_GuildVersatileInfoListMessage(Writer *param1)
{
  param1->writeShort((short)this->guilds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->guilds.size())
  {
    param1->writeShort((short)qSharedPointerCast<GuildVersatileInformations>(this->guilds[_loc2_])->getTypes().last());
    qSharedPointerCast<GuildVersatileInformations>(this->guilds[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void GuildVersatileInfoListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildVersatileInfoListMessage(param1);
}

void GuildVersatileInfoListMessage::deserializeAs_GuildVersatileInfoListMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<GuildVersatileInformations> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<GuildVersatileInformations>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->guilds.append(_loc5_);
    _loc3_++;
  }
}

GuildVersatileInfoListMessage::GuildVersatileInfoListMessage()
{
  m_type = MessageEnum::GUILDVERSATILEINFOLISTMESSAGE;
}

