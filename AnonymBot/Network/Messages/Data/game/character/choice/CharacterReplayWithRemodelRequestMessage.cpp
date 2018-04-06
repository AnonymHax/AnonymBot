#include "CharacterReplayWithRemodelRequestMessage.h"

void CharacterReplayWithRemodelRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterReplayWithRemodelRequestMessage(param1);
}

void CharacterReplayWithRemodelRequestMessage::serializeAs_CharacterReplayWithRemodelRequestMessage(Writer *param1)
{
  CharacterReplayRequestMessage::serializeAs_CharacterReplayRequestMessage(param1);
  this->remodel.serializeAs_RemodelingInformation(param1);
}

void CharacterReplayWithRemodelRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterReplayWithRemodelRequestMessage(param1);
}

void CharacterReplayWithRemodelRequestMessage::deserializeAs_CharacterReplayWithRemodelRequestMessage(Reader *param1)
{
  CharacterReplayRequestMessage::deserialize(param1);
  this->remodel = RemodelingInformation();
  this->remodel.deserialize(param1);
}

CharacterReplayWithRemodelRequestMessage::CharacterReplayWithRemodelRequestMessage()
{
  m_type = MessageEnum::CHARACTERREPLAYWITHREMODELREQUESTMESSAGE;
}

