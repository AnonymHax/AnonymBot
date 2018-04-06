#include "ContactLookRequestByNameMessage.h"

void ContactLookRequestByNameMessage::serialize(Writer *param1)
{
  this->serializeAs_ContactLookRequestByNameMessage(param1);
}

void ContactLookRequestByNameMessage::serializeAs_ContactLookRequestByNameMessage(Writer *param1)
{
  ContactLookRequestMessage::serializeAs_ContactLookRequestMessage(param1);
  param1->writeUTF(this->playerName);
}

void ContactLookRequestByNameMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ContactLookRequestByNameMessage(param1);
}

void ContactLookRequestByNameMessage::deserializeAs_ContactLookRequestByNameMessage(Reader *param1)
{
  ContactLookRequestMessage::deserialize(param1);
  this->playerName = param1->readUTF();
}

ContactLookRequestByNameMessage::ContactLookRequestByNameMessage()
{
  m_type = MessageEnum::CONTACTLOOKREQUESTBYNAMEMESSAGE;
}

