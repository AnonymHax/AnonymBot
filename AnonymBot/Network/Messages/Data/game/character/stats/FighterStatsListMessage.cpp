#include "FighterStatsListMessage.h"

void FighterStatsListMessage::serialize(Writer *param1)
{
  this->serializeAs_FighterStatsListMessage(param1);
}

void FighterStatsListMessage::serializeAs_FighterStatsListMessage(Writer *param1)
{
  this->stats.serializeAs_CharacterCharacteristicsInformations(param1);
}

void FighterStatsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_FighterStatsListMessage(param1);
}

void FighterStatsListMessage::deserializeAs_FighterStatsListMessage(Reader *param1)
{
  this->stats = CharacterCharacteristicsInformations();
  this->stats.deserialize(param1);
}

FighterStatsListMessage::FighterStatsListMessage()
{
  m_type = MessageEnum::FIGHTERSTATSLISTMESSAGE;
}

