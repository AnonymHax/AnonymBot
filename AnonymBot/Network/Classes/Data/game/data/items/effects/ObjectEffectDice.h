#ifndef OBJECTEFFECTDICE_H
#define OBJECTEFFECTDICE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"

class ObjectEffectDice : public ObjectEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffectDice(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffectDice(Reader *param1);
  ObjectEffectDice();
  bool operator==(const ObjectEffectDice &compared);

  uint diceNum;
  uint diceSide;
  uint diceConst;
};

#endif // OBJECTEFFECTDICE_H