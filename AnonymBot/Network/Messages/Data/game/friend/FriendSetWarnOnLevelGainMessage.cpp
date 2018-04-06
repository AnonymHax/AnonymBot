#include "FriendSetWarnOnLevelGainMessage.h"

void FriendSetWarnOnLevelGainMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendSetWarnOnLevelGainMessage(param1);
}

void FriendSetWarnOnLevelGainMessage::serializeAs_FriendSetWarnOnLevelGainMessage(Writer *param1)
{
  param1->writeBool(this->enable);
}

void FriendSetWarnOnLevelGainMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendSetWarnOnLevelGainMessage(param1);
}

void FriendSetWarnOnLevelGainMessage::deserializeAs_FriendSetWarnOnLevelGainMessage(Reader *param1)
{
  this->enable = param1->readBool();
}

FriendSetWarnOnLevelGainMessage::FriendSetWarnOnLevelGainMessage()
{
  m_type = MessageEnum::FRIENDSETWARNONLEVELGAINMESSAGE;
}

