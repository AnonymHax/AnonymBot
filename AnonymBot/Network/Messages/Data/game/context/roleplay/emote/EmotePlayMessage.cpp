#include "EmotePlayMessage.h"

void EmotePlayMessage::serialize(Writer *param1)
{
  this->serializeAs_EmotePlayMessage(param1);
}

void EmotePlayMessage::serializeAs_EmotePlayMessage(Writer *param1)
{
  EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(param1);
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  else
  {
    param1->writeDouble(this->actorId);
    if(this->accountId < 0)
    {
      qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
    }
    else
    {
      param1->writeInt((int)this->accountId);
      return;
    }
  }
}

void EmotePlayMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmotePlayMessage(param1);
}

void EmotePlayMessage::deserializeAs_EmotePlayMessage(Reader *param1)
{
  EmotePlayAbstractMessage::deserialize(param1);
  this->actorId = param1->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->actorId << ") on element of EmotePlayMessage.actorId.";
  }
  else
  {
    this->accountId = param1->readInt();
    if(this->accountId < 0)
    {
      qDebug()<<"ERREUR - EmotePlayMessage -"<<"Forbidden value (" << this->accountId << ") on element of EmotePlayMessage.accountId.";
    }
    else
    {
      return;
    }
  }
}

EmotePlayMessage::EmotePlayMessage()
{
  m_type = MessageEnum::EMOTEPLAYMESSAGE;
}

