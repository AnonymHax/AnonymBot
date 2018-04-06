#ifndef FIGHTENTITYDISPOSITIONINFORMATIONS_H
#define FIGHTENTITYDISPOSITIONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"
#include "Network/Classes/Data/game/context/EntityDispositionInformations.h"

class FightEntityDispositionInformations : public EntityDispositionInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightEntityDispositionInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightEntityDispositionInformations(Reader *param1);
  FightEntityDispositionInformations();
  bool operator==(const FightEntityDispositionInformations &compared);

  double carryingCharacterId;
};

#endif // FIGHTENTITYDISPOSITIONINFORMATIONS_H