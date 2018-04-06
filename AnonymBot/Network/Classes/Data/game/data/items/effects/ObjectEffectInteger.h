#ifndef OBJECTEFFECTINTEGER_H
#define OBJECTEFFECTINTEGER_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectInteger : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectInteger(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectInteger(Reader *param1);
  ObjectEffectInteger();
  bool operator==(const ObjectEffectInteger &compared);

  uint value;
};

#endif // OBJECTEFFECTINTEGER_H