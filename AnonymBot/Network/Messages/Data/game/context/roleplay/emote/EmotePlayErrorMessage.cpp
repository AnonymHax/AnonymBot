#include "EmotePlayErrorMessage.h"

void EmotePlayErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_EmotePlayErrorMessage(param1);
}

void EmotePlayErrorMessage::serializeAs_EmotePlayErrorMessage(Writer *param1)
{
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayErrorMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    return;
  }
}

void EmotePlayErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmotePlayErrorMessage(param1);
}

void EmotePlayErrorMessage::deserializeAs_EmotePlayErrorMessage(Reader *param1)
{
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmotePlayErrorMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmotePlayErrorMessage.emoteId.";
  }
  else
  {
    return;
  }
}

EmotePlayErrorMessage::EmotePlayErrorMessage()
{
  m_type = MessageEnum::EMOTEPLAYERRORMESSAGE;
}

