#include "GuildInformationsMembersMessage.h"

void GuildInformationsMembersMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildInformationsMembersMessage(param1);
}

void GuildInformationsMembersMessage::serializeAs_GuildInformationsMembersMessage(Writer *param1)
{
  param1->writeShort((short)this->members.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->members.size())
  {
    qSharedPointerCast<GuildMember>(this->members[_loc2_])->serializeAs_GuildMember(param1);
    _loc2_++;
  }
}

void GuildInformationsMembersMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildInformationsMembersMessage(param1);
}

void GuildInformationsMembersMessage::deserializeAs_GuildInformationsMembersMessage(Reader *param1)
{
  QSharedPointer<GuildMember> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<GuildMember>(new GuildMember() );
    _loc4_->deserialize(param1);
    this->members.append(_loc4_);
    _loc3_++;
  }
}

GuildInformationsMembersMessage::GuildInformationsMembersMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSMEMBERSMESSAGE;
}

