#ifndef GAMEFIGHTMINIMALSTATS_H
#define GAMEFIGHTMINIMALSTATS_H

#include "Network/Classes/AbstractClass.h"

class GameFightMinimalStats : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightMinimalStats(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightMinimalStats(Reader *param1);
  GameFightMinimalStats();
  bool operator==(const GameFightMinimalStats &compared);

  uint lifePoints;
  uint maxLifePoints;
  uint baseMaxLifePoints;
  uint permanentDamagePercent;
  uint shieldPoints;
  int actionPoints;
  int maxActionPoints;
  int movementPoints;
  int maxMovementPoints;
  double summoner;
  bool summoned;
  int neutralElementResistPercent;
  int earthElementResistPercent;
  int waterElementResistPercent;
  int airElementResistPercent;
  int fireElementResistPercent;
  int neutralElementReduction;
  int earthElementReduction;
  int waterElementReduction;
  int airElementReduction;
  int fireElementReduction;
  int criticalDamageFixedResist;
  int pushDamageFixedResist;
  int pvpNeutralElementResistPercent;
  int pvpEarthElementResistPercent;
  int pvpWaterElementResistPercent;
  int pvpAirElementResistPercent;
  int pvpFireElementResistPercent;
  int pvpNeutralElementReduction;
  int pvpEarthElementReduction;
  int pvpWaterElementReduction;
  int pvpAirElementReduction;
  int pvpFireElementReduction;
  uint dodgePALostProbability;
  uint dodgePMLostProbability;
  int tackleBlock;
  int tackleEvade;
  int fixedDamageReflection;
  uint invisibilityState;
};

#endif // GAMEFIGHTMINIMALSTATS_H