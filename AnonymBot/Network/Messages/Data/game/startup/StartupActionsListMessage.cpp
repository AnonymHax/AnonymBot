#include "StartupActionsListMessage.h"

void StartupActionsListMessage::serialize(Writer *param1)
{
  this->serializeAs_StartupActionsListMessage(param1);
}

void StartupActionsListMessage::serializeAs_StartupActionsListMessage(Writer *param1)
{
  param1->writeShort((short)this->actions.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->actions.size())
  {
    qSharedPointerCast<StartupActionAddObject>(this->actions[_loc2_])->serializeAs_StartupActionAddObject(param1);
    _loc2_++;
  }
}

void StartupActionsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionsListMessage(param1);
}

void StartupActionsListMessage::deserializeAs_StartupActionsListMessage(Reader *param1)
{
  QSharedPointer<StartupActionAddObject> _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = QSharedPointer<StartupActionAddObject>(new StartupActionAddObject() );
    _loc4_->deserialize(param1);
    this->actions.append(_loc4_);
    _loc3_++;
  }
}

StartupActionsListMessage::StartupActionsListMessage()
{
  m_type = MessageEnum::STARTUPACTIONSLISTMESSAGE;
}

