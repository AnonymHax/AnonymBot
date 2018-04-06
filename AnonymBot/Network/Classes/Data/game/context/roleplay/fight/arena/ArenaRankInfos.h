#ifndef ARENARANKINFOS_H
#define ARENARANKINFOS_H

#include "Network/Classes/AbstractClass.h"

class ArenaRankInfos : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ArenaRankInfos(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ArenaRankInfos(Reader *param1);
  ArenaRankInfos();
  bool operator==(const ArenaRankInfos &compared);

  uint rank;
  uint bestRank;
  uint victoryCount;
  uint fightcount;
};

#endif // ARENARANKINFOS_H