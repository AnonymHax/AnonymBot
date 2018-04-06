#include "EmotePlayAbstractMessage.h"

void EmotePlayAbstractMessage::serialize(Writer *param1)
{
  this->serializeAs_EmotePlayAbstractMessage(param1);
}

void EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(Writer *param1)
{
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteStartTime << ") on element emoteStartTime.";
    }
    else
    {
      param1->writeDouble(this->emoteStartTime);
      return;
    }
  }
}

void EmotePlayAbstractMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmotePlayAbstractMessage(param1);
}

void EmotePlayAbstractMessage::deserializeAs_EmotePlayAbstractMessage(Reader *param1)
{
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayAbstractMessage.emoteId.";
  }
  else
  {
    this->emoteStartTime = param1->readDouble();
    if(this->emoteStartTime < -9.007199254740992E15 || this->emoteStartTime > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - EmotePlayAbstractMessage -"<<"Forbidden value (" << this->emoteStartTime << ") on element of EmotePlayAbstractMessage.emoteStartTime.";
    }
    else
    {
      return;
    }
  }
}

EmotePlayAbstractMessage::EmotePlayAbstractMessage()
{
  m_type = MessageEnum::EMOTEPLAYABSTRACTMESSAGE;
}

