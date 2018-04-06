#include "MountFeedRequestMessage.h"

void MountFeedRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_MountFeedRequestMessage(param1);
}

void MountFeedRequestMessage::serializeAs_MountFeedRequestMessage(Writer *param1)
{
  if(this->mountUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountUid << ") on element mountUid.";
  }
  else
  {
    param1->writeVarInt((int)this->mountUid);
    param1->writeByte(this->mountLocation);
    if(this->mountFoodUid < 0)
    {
      qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountFoodUid << ") on element mountFoodUid.";
    }
    else
    {
      param1->writeVarInt((int)this->mountFoodUid);
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element quantity.";
      }
      else
      {
        param1->writeVarInt((int)this->quantity);
        return;
      }
    }
  }
}

void MountFeedRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_MountFeedRequestMessage(param1);
}

void MountFeedRequestMessage::deserializeAs_MountFeedRequestMessage(Reader *param1)
{
  this->mountUid = param1->readVarUhInt();
  if(this->mountUid < 0)
  {
    qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountUid << ") on element of MountFeedRequestMessage.mountUid.";
  }
  else
  {
    this->mountLocation = param1->readByte();
    this->mountFoodUid = param1->readVarUhInt();
    if(this->mountFoodUid < 0)
    {
      qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->mountFoodUid << ") on element of MountFeedRequestMessage.mountFoodUid.";
    }
    else
    {
      this->quantity = param1->readVarUhInt();
      if(this->quantity < 0)
      {
        qDebug()<<"ERREUR - MountFeedRequestMessage -"<<"Forbidden value (" << this->quantity << ") on element of MountFeedRequestMessage.quantity.";
      }
      else
      {
        return;
      }
    }
  }
}

MountFeedRequestMessage::MountFeedRequestMessage()
{
  m_type = MessageEnum::MOUNTFEEDREQUESTMESSAGE;
}

