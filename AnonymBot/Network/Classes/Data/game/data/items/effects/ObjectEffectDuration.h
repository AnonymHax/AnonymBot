#ifndef OBJECTEFFECTDURATION_H
#define OBJECTEFFECTDURATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectDuration : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectDuration(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectDuration(Reader *param1);
  ObjectEffectDuration();
  bool operator==(const ObjectEffectDuration &compared);

  uint days;
  uint hours;
  uint minutes;
};

#endif // OBJECTEFFECTDURATION_H