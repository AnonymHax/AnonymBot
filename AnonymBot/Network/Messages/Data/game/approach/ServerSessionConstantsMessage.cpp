#include "ServerSessionConstantsMessage.h"

void ServerSessionConstantsMessage::serialize(Writer *param1)
{
  this->serializeAs_ServerSessionConstantsMessage(param1);
}

void ServerSessionConstantsMessage::serializeAs_ServerSessionConstantsMessage(Writer *param1)
{
  param1->writeShort((short)this->variables.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->variables.size())
  {
    param1->writeShort((short)qSharedPointerCast<ServerSessionConstant>(this->variables[_loc2_])->getTypes().last());
    qSharedPointerCast<ServerSessionConstant>(this->variables[_loc2_])->serialize(param1);
    _loc2_++;
  }
}

void ServerSessionConstantsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ServerSessionConstantsMessage(param1);
}

void ServerSessionConstantsMessage::deserializeAs_ServerSessionConstantsMessage(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<ServerSessionConstant> _loc5_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readUShort();
    _loc5_ = qSharedPointerCast<ServerSessionConstant>(ClassManagerSingleton::get()->getClass(_loc4_));
    _loc5_->deserialize(param1);
    this->variables.append(_loc5_);
    _loc3_++;
  }
}

ServerSessionConstantsMessage::ServerSessionConstantsMessage()
{
  m_type = MessageEnum::SERVERSESSIONCONSTANTSMESSAGE;
}

