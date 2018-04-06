#include "BulletinMessage.h"

void BulletinMessage::serialize(Writer *param1)
{
  this->serializeAs_BulletinMessage(param1);
}

void BulletinMessage::serializeAs_BulletinMessage(Writer *param1)
{
  SocialNoticeMessage::serializeAs_SocialNoticeMessage(param1);
  if(this->lastNotifiedTimestamp < 0)
  {
    qDebug()<<"ERREUR - BulletinMessage -"<<"Forbidden value (" << this->lastNotifiedTimestamp << ") on element lastNotifiedTimestamp.";
  }
  else
  {
    param1->writeInt((int)this->lastNotifiedTimestamp);
    return;
  }
}

void BulletinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BulletinMessage(param1);
}

void BulletinMessage::deserializeAs_BulletinMessage(Reader *param1)
{
  SocialNoticeMessage::deserialize(param1);
  this->lastNotifiedTimestamp = param1->readInt();
  if(this->lastNotifiedTimestamp < 0)
  {
    qDebug()<<"ERREUR - BulletinMessage -"<<"Forbidden value (" << this->lastNotifiedTimestamp << ") on element of BulletinMessage.lastNotifiedTimestamp.";
  }
  else
  {
    return;
  }
}

BulletinMessage::BulletinMessage()
{
  m_type = MessageEnum::BULLETINMESSAGE;
}

