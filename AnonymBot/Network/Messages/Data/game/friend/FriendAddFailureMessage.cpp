#include "FriendAddFailureMessage.h"

void FriendAddFailureMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendAddFailureMessage(param1);
}

void FriendAddFailureMessage::serializeAs_FriendAddFailureMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void FriendAddFailureMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendAddFailureMessage(param1);
}

void FriendAddFailureMessage::deserializeAs_FriendAddFailureMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - FriendAddFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of FriendAddFailureMessage.reason.";
  }
  else
  {
    return;
  }
}

FriendAddFailureMessage::FriendAddFailureMessage()
{
  m_type = MessageEnum::FRIENDADDFAILUREMESSAGE;
}

