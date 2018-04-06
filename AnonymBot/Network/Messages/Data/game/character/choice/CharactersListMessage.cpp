#include "CharactersListMessage.h"

void CharactersListMessage::serialize(Writer *param1)
{
  this->serializeAs_CharactersListMessage(param1);
}

void CharactersListMessage::serializeAs_CharactersListMessage(Writer *param1)
{
  BasicCharactersListMessage::serializeAs_BasicCharactersListMessage(param1);
  param1->writeBool(this->hasStartupActions);
}

void CharactersListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharactersListMessage(param1);
}

void CharactersListMessage::deserializeAs_CharactersListMessage(Reader *param1)
{
  BasicCharactersListMessage::deserialize(param1);
  this->hasStartupActions = param1->readBool();
}

CharactersListMessage::CharactersListMessage()
{
  m_type = MessageEnum::CHARACTERSLISTMESSAGE;
}

