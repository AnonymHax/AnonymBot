#include "EmoteAddMessage.h"

void EmoteAddMessage::serialize(Writer *param1)
{
  this->serializeAs_EmoteAddMessage(param1);
}

void EmoteAddMessage::serializeAs_EmoteAddMessage(Writer *param1)
{
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmoteAddMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    return;
  }
}

void EmoteAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmoteAddMessage(param1);
}

void EmoteAddMessage::deserializeAs_EmoteAddMessage(Reader *param1)
{
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmoteAddMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmoteAddMessage.emoteId.";
  }
  else
  {
    return;
  }
}

EmoteAddMessage::EmoteAddMessage()
{
  m_type = MessageEnum::EMOTEADDMESSAGE;
}

