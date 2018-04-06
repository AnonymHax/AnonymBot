#ifndef OBJECTEFFECTSTRING_H
#define OBJECTEFFECTSTRING_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectString : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectString(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectString(Reader *param1);
  ObjectEffectString();
  bool operator==(const ObjectEffectString &compared);

  QString value;
};

#endif // OBJECTEFFECTSTRING_H