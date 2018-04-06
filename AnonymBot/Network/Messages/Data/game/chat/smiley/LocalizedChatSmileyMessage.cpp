#include "LocalizedChatSmileyMessage.h"

void LocalizedChatSmileyMessage::serialize(Writer *param1)
{
  this->serializeAs_LocalizedChatSmileyMessage(param1);
}

void LocalizedChatSmileyMessage::serializeAs_LocalizedChatSmileyMessage(Writer *param1)
{
  ChatSmileyMessage::serializeAs_ChatSmileyMessage(param1);
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - LocalizedChatSmileyMessage -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    return;
  }
}

void LocalizedChatSmileyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_LocalizedChatSmileyMessage(param1);
}

void LocalizedChatSmileyMessage::deserializeAs_LocalizedChatSmileyMessage(Reader *param1)
{
  ChatSmileyMessage::deserialize(param1);
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - LocalizedChatSmileyMessage -"<<"Forbidden value (" << this->cellId << ") on element of LocalizedChatSmileyMessage.cellId.";
  }
  else
  {
    return;
  }
}

LocalizedChatSmileyMessage::LocalizedChatSmileyMessage()
{
  m_type = MessageEnum::LOCALIZEDCHATSMILEYMESSAGE;
}

