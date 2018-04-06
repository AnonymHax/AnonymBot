#include "ContactLookRequestByIdMessage.h"

void ContactLookRequestByIdMessage::serialize(Writer *param1)
{
  this->serializeAs_ContactLookRequestByIdMessage(param1);
}

void ContactLookRequestByIdMessage::serializeAs_ContactLookRequestByIdMessage(Writer *param1)
{
  ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookRequestByIdMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void ContactLookRequestByIdMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ContactLookRequestByIdMessage(param1);
}

void ContactLookRequestByIdMessage::deserializeAs_ContactLookRequestByIdMessage(Reader *param1)
{
  ContactLookRequestMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ContactLookRequestByIdMessage -"<<"Forbidden value (" << this->playerId << ") on element of ContactLookRequestByIdMessage.playerId.";
  }
  else
  {
    return;
  }
}

ContactLookRequestByIdMessage::ContactLookRequestByIdMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTBYIDMESSAGE;
}

