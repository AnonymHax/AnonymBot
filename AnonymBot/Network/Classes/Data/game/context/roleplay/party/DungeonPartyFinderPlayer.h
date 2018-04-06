#ifndef DUNGEONPARTYFINDERPLAYER_H
#define DUNGEONPARTYFINDERPLAYER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Enum/Data/PlayableBreedEnum.h"

class DungeonPartyFinderPlayer : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderPlayer(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderPlayer(Reader *param1);
  DungeonPartyFinderPlayer();
  bool operator==(const DungeonPartyFinderPlayer &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;
  uint level;
};

#endif // DUNGEONPARTYFINDERPLAYER_H