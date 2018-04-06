#include "CharacterNameSuggestionFailureMessage.h"

void CharacterNameSuggestionFailureMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterNameSuggestionFailureMessage(param1);
}

void CharacterNameSuggestionFailureMessage::serializeAs_CharacterNameSuggestionFailureMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void CharacterNameSuggestionFailureMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterNameSuggestionFailureMessage(param1);
}

void CharacterNameSuggestionFailureMessage::deserializeAs_CharacterNameSuggestionFailureMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - CharacterNameSuggestionFailureMessage -"<<"Forbidden value (" << this->reason << ") on element of CharacterNameSuggestionFailureMessage.reason.";
  }
  else
  {
    return;
  }
}

CharacterNameSuggestionFailureMessage::CharacterNameSuggestionFailureMessage()
{
  m_type = MessageEnum::CHARACTERNAMESUGGESTIONFAILUREMESSAGE;
}

