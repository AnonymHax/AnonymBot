#include "ContactLookErrorMessage.h"

void ContactLookErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_ContactLookErrorMessage(param1);
}

void ContactLookErrorMessage::serializeAs_ContactLookErrorMessage(Writer *param1)
{
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookErrorMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeVarInt((int)this->requestId);
    return;
  }
}

void ContactLookErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ContactLookErrorMessage(param1);
}

void ContactLookErrorMessage::deserializeAs_ContactLookErrorMessage(Reader *param1)
{
  this->requestId = param1->readVarUhInt();
  if(this->requestId < 0)
  {
    qDebug()<<"ERREUR - ContactLookErrorMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookErrorMessage.requestId.";
  }
  else
  {
    return;
  }
}

ContactLookErrorMessage::ContactLookErrorMessage()
{
  m_type = MessageEnum::CONTACTLOOKERRORMESSAGE;
}

