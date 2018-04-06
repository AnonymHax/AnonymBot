#include "CharacterFirstSelectionMessage.h"

void CharacterFirstSelectionMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterFirstSelectionMessage(param1);
}

void CharacterFirstSelectionMessage::serializeAs_CharacterFirstSelectionMessage(Writer *param1)
{
  CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(param1);
  param1->writeBool(this->doTutorial);
}

void CharacterFirstSelectionMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterFirstSelectionMessage(param1);
}

void CharacterFirstSelectionMessage::deserializeAs_CharacterFirstSelectionMessage(Reader *param1)
{
  CharacterSelectionMessage::deserialize(param1);
  this->doTutorial = param1->readBool();
}

CharacterFirstSelectionMessage::CharacterFirstSelectionMessage()
{
  m_type = MessageEnum::CHARACTERFIRSTSELECTIONMESSAGE;
}

