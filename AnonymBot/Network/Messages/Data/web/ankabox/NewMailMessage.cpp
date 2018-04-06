#include "NewMailMessage.h"

void NewMailMessage::serialize(Writer *param1)
{
  this->serializeAs_NewMailMessage(param1);
}

void NewMailMessage::serializeAs_NewMailMessage(Writer *param1)
{
  MailStatusMessage::serializeAs_MailStatusMessage(param1);
  param1->writeShort((short)this->sendersAccountId.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->sendersAccountId.size())
  {
    if(this->sendersAccountId[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - NewMailMessage -"<<"Forbidden value (" << this->sendersAccountId[_loc2_] << ") on element 1 (starting at 1) of sendersAccountId.";
    }
    else
    {
      param1->writeInt((int)this->sendersAccountId[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void NewMailMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NewMailMessage(param1);
}

void NewMailMessage::deserializeAs_NewMailMessage(Reader *param1)
{
  uint _loc4_ = 0;
  MailStatusMessage::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readInt();
    if(_loc4_ < 0)
    {
      qDebug()<<"ERREUR - NewMailMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of sendersAccountId.";
    }
    else
    {
      this->sendersAccountId.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

NewMailMessage::NewMailMessage()
{
  m_type = MessageEnum::NEWMAILMESSAGE;
}

