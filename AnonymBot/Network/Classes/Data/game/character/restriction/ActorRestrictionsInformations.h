#ifndef ACTORRESTRICTIONSINFORMATIONS_H
#define ACTORRESTRICTIONSINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class ActorRestrictionsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ActorRestrictionsInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ActorRestrictionsInformations(Reader *param1);
  ActorRestrictionsInformations();
  bool operator==(const ActorRestrictionsInformations &compared);

  bool cantBeAggressed;
  bool cantBeChallenged;
  bool cantTrade;
  bool cantBeAttackedByMutant;
  bool cantRun;
  bool forceSlowWalk;
  bool cantMinimize;
  bool cantMove;
  bool cantAggress;
  bool cantChallenge;
  bool cantExchange;
  bool cantAttack;
  bool cantChat;
  bool cantBeMerchant;
  bool cantUseObject;
  bool cantUseTaxCollector;
  bool cantUseInteractive;
  bool cantSpeakToNPC;
  bool cantChangeZone;
  bool cantAttackMonster;
  bool cantWalk8Directions;
};

#endif // ACTORRESTRICTIONSINFORMATIONS_H