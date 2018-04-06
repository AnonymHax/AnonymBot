#ifndef OBJECTEFFECTMOUNT_H
#define OBJECTEFFECTMOUNT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectMount : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectMount(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectMount(Reader *param1);
  ObjectEffectMount();
  bool operator==(const ObjectEffectMount &compared);

  uint mountId;
  double date;
  uint modelId;
};

#endif // OBJECTEFFECTMOUNT_H