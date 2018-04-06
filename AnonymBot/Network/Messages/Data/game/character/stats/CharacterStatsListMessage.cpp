#include "CharacterStatsListMessage.h"

void CharacterStatsListMessage::serialize(Writer *param1)
{
  this->serializeAs_CharacterStatsListMessage(param1);
}

void CharacterStatsListMessage::serializeAs_CharacterStatsListMessage(Writer *param1)
{
  this->stats.serializeAs_CharacterCharacteristicsInformations(param1);
}

void CharacterStatsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CharacterStatsListMessage(param1);
}

void CharacterStatsListMessage::deserializeAs_CharacterStatsListMessage(Reader *param1)
{
  this->stats = CharacterCharacteristicsInformations();
  this->stats.deserialize(param1);
}

CharacterStatsListMessage::CharacterStatsListMessage()
{
  m_type = MessageEnum::CHARACTERSTATSLISTMESSAGE;
}

