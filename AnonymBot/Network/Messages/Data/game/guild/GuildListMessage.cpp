#include "GuildListMessage.h"

void GuildListMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildListMessage(param1);
}

void GuildListMessage::serializeAs_GuildListMessage(Writer *param1)
{
  param1->writeShort((short)this->guilds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->guilds.size())
  {
    qSharedPointerCast<GuildInformations>(this->guilds[_loc2_])->serializeAs_GuildInformations(param1);
    _loc2_++;
  }
}

void GuildListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildListMessage(param1);
}

void GuildListMessage::deserializeAs_GuildListMessage(Reader *param1)
{
  QSharedPointer<GuildInformations> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<GuildInformations>(new GuildInformations() );
    _loc4_->deserialize(param1);
    this->guilds.append(_loc4_);
    _loc3_++;
  }
}

GuildListMessage::GuildListMessage()
{
  m_type = MessageEnum::GUILDLISTMESSAGE;
}

