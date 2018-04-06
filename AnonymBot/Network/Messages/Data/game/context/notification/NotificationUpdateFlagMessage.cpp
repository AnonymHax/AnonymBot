#include "NotificationUpdateFlagMessage.h"

void NotificationUpdateFlagMessage::serialize(Writer *param1)
{
  this->serializeAs_NotificationUpdateFlagMessage(param1);
}

void NotificationUpdateFlagMessage::serializeAs_NotificationUpdateFlagMessage(Writer *param1)
{
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - NotificationUpdateFlagMessage -"<<"Forbidden value (" << this->index << ") on element index.";
  }
  else
  {
    param1->writeVarShort((int)this->index);
    return;
  }
}

void NotificationUpdateFlagMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NotificationUpdateFlagMessage(param1);
}

void NotificationUpdateFlagMessage::deserializeAs_NotificationUpdateFlagMessage(Reader *param1)
{
  this->index = param1->readVarUhShort();
  if(this->index < 0)
  {
    qDebug()<<"ERREUR - NotificationUpdateFlagMessage -"<<"Forbidden value (" << this->index << ") on element of NotificationUpdateFlagMessage.index.";
  }
  else
  {
    return;
  }
}

NotificationUpdateFlagMessage::NotificationUpdateFlagMessage()
{
  m_type = MessageEnum::NOTIFICATIONUPDATEFLAGMESSAGE;
}

