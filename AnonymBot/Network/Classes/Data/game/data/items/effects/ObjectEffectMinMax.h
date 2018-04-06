#ifndef OBJECTEFFECTMINMAX_H
#define OBJECTEFFECTMINMAX_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectMinMax : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectMinMax(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectMinMax(Reader *param1);
  ObjectEffectMinMax();
  bool operator==(const ObjectEffectMinMax &compared);

  uint min;
  uint max;
};

#endif // OBJECTEFFECTMINMAX_H