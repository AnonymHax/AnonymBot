#ifndef CHARACTERSTATSLISTMESSAGE_H
#define CHARACTERSTATSLISTMESSAGE_H

#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"

class CharacterStatsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterStatsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterStatsListMessage(Reader *param1);
  CharacterStatsListMessage();

  CharacterCharacteristicsInformations stats;
};

#endif // CHARACTERSTATSLISTMESSAGE_H