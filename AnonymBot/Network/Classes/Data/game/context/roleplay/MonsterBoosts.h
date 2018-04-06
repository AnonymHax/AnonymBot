#ifndef MONSTERBOOSTS_H
#define MONSTERBOOSTS_H

#include "Network/Classes/AbstractClass.h"

class MonsterBoosts : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MonsterBoosts(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MonsterBoosts(Reader *param1);
  MonsterBoosts();
  bool operator==(const MonsterBoosts &compared);

  uint id;
  uint xpBoost;
  uint dropBoost;
};

#endif // MONSTERBOOSTS_H