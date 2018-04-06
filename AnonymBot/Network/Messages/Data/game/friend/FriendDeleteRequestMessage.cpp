#include "FriendDeleteRequestMessage.h"

void FriendDeleteRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_FriendDeleteRequestMessage(param1);
}

void FriendDeleteRequestMessage::serializeAs_FriendDeleteRequestMessage(Writer *param1)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - FriendDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    return;
  }
}

void FriendDeleteRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FriendDeleteRequestMessage(param1);
}

void FriendDeleteRequestMessage::deserializeAs_FriendDeleteRequestMessage(Reader *param1)
{
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - FriendDeleteRequestMessage -"<<"Forbidden value (" << this->accountId << ") on element of FriendDeleteRequestMessage.accountId.";
  }
  else
  {
    return;
  }
}

FriendDeleteRequestMessage::FriendDeleteRequestMessage()
{
  m_type = MessageEnum::FRIENDDELETEREQUESTMESSAGE;
}

