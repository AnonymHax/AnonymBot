#include "EmotePlayRequestMessage.h"

void EmotePlayRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_EmotePlayRequestMessage(param1);
}

void EmotePlayRequestMessage::serializeAs_EmotePlayRequestMessage(Writer *param1)
{
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayRequestMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    return;
  }
}

void EmotePlayRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmotePlayRequestMessage(param1);
}

void EmotePlayRequestMessage::deserializeAs_EmotePlayRequestMessage(Reader *param1)
{
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayRequestMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayRequestMessage.emoteId.";
  }
  else
  {
    return;
  }
}

EmotePlayRequestMessage::EmotePlayRequestMessage()
{
  m_type = MessageEnum::EMOTEPLAYREQUESTMESSAGE;
}

