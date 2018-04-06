#ifndef FIGHTLOOT_H
#define FIGHTLOOT_H

#include "Network/Classes/AbstractClass.h"

class FightLoot : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightLoot(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightLoot(Reader *param1);
  FightLoot();
  bool operator==(const FightLoot &compared);

  QList<uint> objects;
  uint kamas;
};

#endif // FIGHTLOOT_H