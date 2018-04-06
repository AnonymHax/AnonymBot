#include "SocialNoticeSetErrorMessage.h"

void SocialNoticeSetErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_SocialNoticeSetErrorMessage(param1);
}

void SocialNoticeSetErrorMessage::serializeAs_SocialNoticeSetErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void SocialNoticeSetErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SocialNoticeSetErrorMessage(param1);
}

void SocialNoticeSetErrorMessage::deserializeAs_SocialNoticeSetErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - SocialNoticeSetErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of SocialNoticeSetErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

SocialNoticeSetErrorMessage::SocialNoticeSetErrorMessage()
{
  m_type = MessageEnum::SOCIALNOTICESETERRORMESSAGE;
}

