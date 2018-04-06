#ifndef GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H
#define GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"

class GuildFightPlayersEnemiesListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightPlayersEnemiesListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightPlayersEnemiesListMessage(Reader *param1);
  GuildFightPlayersEnemiesListMessage();

  uint fightId;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> playerInfo;
};

#endif // GUILDFIGHTPLAYERSENEMIESLISTMESSAGE_H