#ifndef OBJECTEFFECTLADDER_H
#define OBJECTEFFECTLADDER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectCreature.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffectCreature.h"

class ObjectEffectLadder : public ObjectEffectCreature
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectLadder(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectLadder(Reader *param1);
  ObjectEffectLadder();
  bool operator==(const ObjectEffectLadder &compared);

  uint monsterCount;
};

#endif // OBJECTEFFECTLADDER_H