#include "IdentificationSuccessWithLoginTokenMessage.h"

void IdentificationSuccessWithLoginTokenMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationSuccessWithLoginTokenMessage(param1);
}

void IdentificationSuccessWithLoginTokenMessage::serializeAs_IdentificationSuccessWithLoginTokenMessage(Writer *param1)
{
  IdentificationSuccessMessage::serializeAs_IdentificationSuccessMessage(param1);
  param1->writeUTF(this->loginToken);
}

void IdentificationSuccessWithLoginTokenMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationSuccessWithLoginTokenMessage(param1);
}

void IdentificationSuccessWithLoginTokenMessage::deserializeAs_IdentificationSuccessWithLoginTokenMessage(Reader *param1)
{
  IdentificationSuccessMessage::deserialize(param1);
  this->loginToken = param1->readUTF();
}

IdentificationSuccessWithLoginTokenMessage::IdentificationSuccessWithLoginTokenMessage()
{
  m_type = MessageEnum::IDENTIFICATIONSUCCESSWITHLOGINTOKENMESSAGE;
}

