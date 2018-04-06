#ifndef FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H
#define FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/Data/game/actions/fight/AbstractFightDispellableEffect.h"
#include "Network/Classes/ClassManager.h"

class FightDispellableEffectExtendedInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightDispellableEffectExtendedInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightDispellableEffectExtendedInformations(Reader *param1);
  FightDispellableEffectExtendedInformations();
  bool operator==(const FightDispellableEffectExtendedInformations &compared);

  uint actionId;
  double sourceId;
  QSharedPointer<AbstractFightDispellableEffect> effect;
};

#endif // FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS_H