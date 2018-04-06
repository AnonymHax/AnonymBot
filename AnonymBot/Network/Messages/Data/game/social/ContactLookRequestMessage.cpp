#include "ContactLookRequestMessage.h"

void ContactLookRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_ContactLookRequestMessage(param1);
}

void ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(Writer *param1)
{
  if(this->requestId < 0 || this->requestId > 255)
  {
    qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->requestId << ") on element requestId.";
  }
  else
  {
    param1->writeByte(this->requestId);
    param1->writeByte(this->contactType);
    return;
  }
}

void ContactLookRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ContactLookRequestMessage(param1);
}

void ContactLookRequestMessage::deserializeAs_ContactLookRequestMessage(Reader *param1)
{
  this->requestId = param1->readUByte();
  if(this->requestId < 0 || this->requestId > 255)
  {
    qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->requestId << ") on element of ContactLookRequestMessage.requestId.";
  }
  else
  {
    this->contactType = param1->readByte();
    if(this->contactType < 0)
    {
      qDebug()<<"ERREUR - ContactLookRequestMessage -"<<"Forbidden value (" << this->contactType << ") on element of ContactLookRequestMessage.contactType.";
    }
    else
    {
      return;
    }
  }
}

ContactLookRequestMessage::ContactLookRequestMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTMESSAGE;
}

