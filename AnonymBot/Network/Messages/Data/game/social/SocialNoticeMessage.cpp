#include "SocialNoticeMessage.h"

void SocialNoticeMessage::serialize(Writer *param1)
{
  this->serializeAs_SocialNoticeMessage(param1);
}

void SocialNoticeMessage::serializeAs_SocialNoticeMessage(Writer *param1)
{
  param1->writeUTF(this->content);
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->timestamp << ") on element timestamp.";
  }
  else
  {
    param1->writeInt((int)this->timestamp);
    if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->memberId << ") on element memberId.";
    }
    else
    {
      param1->writeVarLong((double)this->memberId);
      param1->writeUTF(this->memberName);
      return;
    }
  }
}

void SocialNoticeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SocialNoticeMessage(param1);
}

void SocialNoticeMessage::deserializeAs_SocialNoticeMessage(Reader *param1)
{
  this->content = param1->readUTF();
  this->timestamp = param1->readInt();
  if(this->timestamp < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->timestamp << ") on element of SocialNoticeMessage.timestamp.";
  }
  else
  {
    this->memberId = param1->readVarUhLong();
    if(this->memberId < 0 || this->memberId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SocialNoticeMessage -"<<"Forbidden value (" << this->memberId << ") on element of SocialNoticeMessage.memberId.";
    }
    else
    {
      this->memberName = param1->readUTF();
      return;
    }
  }
}

SocialNoticeMessage::SocialNoticeMessage()
{
  m_type = MessageEnum::SOCIALNOTICEMESSAGE;
}

