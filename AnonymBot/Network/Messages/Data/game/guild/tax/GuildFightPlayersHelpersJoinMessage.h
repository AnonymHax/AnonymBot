#ifndef GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H
#define GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"

class GuildFightPlayersHelpersJoinMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightPlayersHelpersJoinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightPlayersHelpersJoinMessage(Reader *param1);
  GuildFightPlayersHelpersJoinMessage();

  uint fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> playerInfo;
};

#endif // GUILDFIGHTPLAYERSHELPERSJOINMESSAGE_H