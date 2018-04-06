#include "NotificationByServerMessage.h"

void NotificationByServerMessage::serialize(Writer *param1)
{
  this->serializeAs_NotificationByServerMessage(param1);
}

void NotificationByServerMessage::serializeAs_NotificationByServerMessage(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - NotificationByServerMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    param1->writeShort((short)this->parameters.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->parameters.size())
    {
      param1->writeUTF(this->parameters[_loc2_]);
      _loc2_++;
    }
    param1->writeBool(this->forceOpen);
    return;
  }
}

void NotificationByServerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NotificationByServerMessage(param1);
}

void NotificationByServerMessage::deserializeAs_NotificationByServerMessage(Reader *param1)
{
  QString _loc4_ ;
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - NotificationByServerMessage -"<<"Forbidden value (" << this->id << ") on element of NotificationByServerMessage.id.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUTF();
      this->parameters.append(_loc4_);
      _loc3_++;
    }
    this->forceOpen = param1->readBool();
    return;
  }
}

NotificationByServerMessage::NotificationByServerMessage()
{
  m_type = MessageEnum::NOTIFICATIONBYSERVERMESSAGE;
}

