#ifndef OBJECTEFFECTCREATURE_H
#define OBJECTEFFECTCREATURE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectCreature : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectCreature(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectCreature(Reader *param1);
  ObjectEffectCreature();
  bool operator==(const ObjectEffectCreature &compared);

  uint monsterFamilyId;
};

#endif // OBJECTEFFECTCREATURE_H