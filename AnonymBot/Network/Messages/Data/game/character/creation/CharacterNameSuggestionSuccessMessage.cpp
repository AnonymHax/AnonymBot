#include "CharacterNameSuggestionSuccessMessage.h"

void CharacterNameSuggestionSuccessMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterNameSuggestionSuccessMessage(param1);
}

void CharacterNameSuggestionSuccessMessage::serializeAs_CharacterNameSuggestionSuccessMessage(Writer *param1)
{
  param1->writeUTF(this->suggestion);
}

void CharacterNameSuggestionSuccessMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterNameSuggestionSuccessMessage(param1);
}

void CharacterNameSuggestionSuccessMessage::deserializeAs_CharacterNameSuggestionSuccessMessage(Reader *param1)
{
  this->suggestion = param1->readUTF();
}

CharacterNameSuggestionSuccessMessage::CharacterNameSuggestionSuccessMessage()
{
  m_type = MessageEnum::CHARACTERNAMESUGGESTIONSUCCESSMESSAGE;
}

