#ifndef OBJECTEFFECTDATE_H
#define OBJECTEFFECTDATE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectDate : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectDate(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectDate(Reader *param1);
  ObjectEffectDate();
  bool operator==(const ObjectEffectDate &compared);

  uint year;
  uint month;
  uint day;
  uint hour;
  uint minute;
};

#endif // OBJECTEFFECTDATE_H