#ifndef FIGHTTRIGGEREDEFFECT_H
#define FIGHTTRIGGEREDEFFECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"

class FightTriggeredEffect : public AbstractFightDispellableEffect
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightTriggeredEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightTriggeredEffect(Reader *param1);
  FightTriggeredEffect();
  bool operator==(const FightTriggeredEffect &compared);

  int param1;
  int param2;
  int param3;
  int delay;
};

#endif // FIGHTTRIGGEREDEFFECT_H