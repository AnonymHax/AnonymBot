#include "EmoteRemoveMessage.h"

void EmoteRemoveMessage::serialize(Writer *param1)
{
  this->serializeAs_EmoteRemoveMessage(param1);
}

void EmoteRemoveMessage::serializeAs_EmoteRemoveMessage(Writer *param1)
{
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmoteRemoveMessage -"<<"Forbidden value (" << this->emoteId << ") on element emoteId.";
  }
  else
  {
    param1->writeByte(this->emoteId);
    return;
  }
}

void EmoteRemoveMessage::deserialize(Reader *param1)
{
  this->deserializeAs_EmoteRemoveMessage(param1);
}

void EmoteRemoveMessage::deserializeAs_EmoteRemoveMessage(Reader *param1)
{
  this->emoteId = param1->readUByte();
  if(this->emoteId < 0 || this->emoteId > 255)
  {
    qDebug()<<"ERREUR - EmoteRemoveMessage -"<<"Forbidden value (" << this->emoteId << ") on element of EmoteRemoveMessage.emoteId.";
  }
  else
  {
    return;
  }
}

EmoteRemoveMessage::EmoteRemoveMessage()
{
  m_type = MessageEnum::EMOTEREMOVEMESSAGE;
}

