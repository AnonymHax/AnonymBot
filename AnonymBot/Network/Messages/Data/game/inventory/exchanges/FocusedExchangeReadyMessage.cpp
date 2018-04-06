#include "FocusedExchangeReadyMessage.h"

void FocusedExchangeReadyMessage::serialize(Writer *param1)
{
  this->serializeAs_FocusedExchangeReadyMessage(param1);
}

void FocusedExchangeReadyMessage::serializeAs_FocusedExchangeReadyMessage(Writer *param1)
{
  ExchangeReadyMessage::serializeAs_ExchangeReadyMessage(param1);
  if(this->focusActionId < 0)
  {
    qDebug()<<"ERREUR - FocusedExchangeReadyMessage -"<<"Forbidden value (" << this->focusActionId << ") on element focusActionId.";
  }
  else
  {
    param1->writeVarInt((int)this->focusActionId);
    return;
  }
}

void FocusedExchangeReadyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FocusedExchangeReadyMessage(param1);
}

void FocusedExchangeReadyMessage::deserializeAs_FocusedExchangeReadyMessage(Reader *param1)
{
  ExchangeReadyMessage::deserialize(param1);
  this->focusActionId = param1->readVarUhInt();
  if(this->focusActionId < 0)
  {
    qDebug()<<"ERREUR - FocusedExchangeReadyMessage -"<<"Forbidden value (" << this->focusActionId << ") on element of FocusedExchangeReadyMessage.focusActionId.";
  }
  else
  {
    return;
  }
}

FocusedExchangeReadyMessage::FocusedExchangeReadyMessage()
{
  m_type = MessageEnum::FOCUSEDEXCHANGEREADYMESSAGE;
}

