#include "CharacterSelectionWithRemodelMessage.h"

void CharacterSelectionWithRemodelMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterSelectionWithRemodelMessage(param1);
}

void CharacterSelectionWithRemodelMessage::serializeAs_CharacterSelectionWithRemodelMessage(Writer *param1)
{
  CharacterSelectionMessage::serializeAs_CharacterSelectionMessage(param1);
  this->remodel.serializeAs_RemodelingInformation(param1);
}

void CharacterSelectionWithRemodelMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterSelectionWithRemodelMessage(param1);
}

void CharacterSelectionWithRemodelMessage::deserializeAs_CharacterSelectionWithRemodelMessage(Reader *param1)
{
  CharacterSelectionMessage::deserialize(param1);
  this->remodel = RemodelingInformation();
  this->remodel.deserialize(param1);
}

CharacterSelectionWithRemodelMessage::CharacterSelectionWithRemodelMessage()
{
  m_type = MessageEnum::CHARACTERSELECTIONWITHREMODELMESSAGE;
}

