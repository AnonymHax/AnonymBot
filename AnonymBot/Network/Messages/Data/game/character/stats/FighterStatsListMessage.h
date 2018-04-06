#ifndef FIGHTERSTATSLISTMESSAGE_H
#define FIGHTERSTATSLISTMESSAGE_H

#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"

class FighterStatsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FighterStatsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FighterStatsListMessage(Reader *param1);
  FighterStatsListMessage();

  CharacterCharacteristicsInformations stats;
};

#endif // FIGHTERSTATSLISTMESSAGE_H