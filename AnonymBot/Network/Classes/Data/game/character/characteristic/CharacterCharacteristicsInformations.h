#ifndef CHARACTERCHARACTERISTICSINFORMATIONS_H
#define CHARACTERCHARACTERISTICSINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/alignment/ActorExtendedAlignmentInformations.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterBaseCharacteristic.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterSpellModification.h"
#include "Network/Classes/Data/game/character/alignment/ActorExtendedAlignmentInformations.h"

class CharacterCharacteristicsInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CharacterCharacteristicsInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CharacterCharacteristicsInformations(Reader *param1);
  CharacterCharacteristicsInformations();
  bool operator==(const CharacterCharacteristicsInformations &compared);

  double experience;
  double experienceLevelFloor;
  double experienceNextLevelFloor;
  double experienceBonusLimit;
  uint kamas;
  uint statsPoints;
  uint additionnalPoints;
  uint spellsPoints;
  ActorExtendedAlignmentInformations alignmentInfos;
  uint lifePoints;
  uint maxLifePoints;
  uint energyPoints;
  uint maxEnergyPoints;
  int actionPointsCurrent;
  int movementPointsCurrent;
  CharacterBaseCharacteristic initiative;
  CharacterBaseCharacteristic prospecting;
  CharacterBaseCharacteristic actionPoints;
  CharacterBaseCharacteristic movementPoints;
  CharacterBaseCharacteristic strength;
  CharacterBaseCharacteristic vitality;
  CharacterBaseCharacteristic wisdom;
  CharacterBaseCharacteristic chance;
  CharacterBaseCharacteristic agility;
  CharacterBaseCharacteristic intelligence;
  CharacterBaseCharacteristic range;
  CharacterBaseCharacteristic summonableCreaturesBoost;
  CharacterBaseCharacteristic reflect;
  CharacterBaseCharacteristic criticalHit;
  uint criticalHitWeapon;
  CharacterBaseCharacteristic criticalMiss;
  CharacterBaseCharacteristic healBonus;
  CharacterBaseCharacteristic allDamagesBonus;
  CharacterBaseCharacteristic weaponDamagesBonusPercent;
  CharacterBaseCharacteristic damagesBonusPercent;
  CharacterBaseCharacteristic trapBonus;
  CharacterBaseCharacteristic trapBonusPercent;
  CharacterBaseCharacteristic glyphBonusPercent;
  CharacterBaseCharacteristic runeBonusPercent;
  CharacterBaseCharacteristic permanentDamagePercent;
  CharacterBaseCharacteristic tackleBlock;
  CharacterBaseCharacteristic tackleEvade;
  CharacterBaseCharacteristic PAAttack;
  CharacterBaseCharacteristic PMAttack;
  CharacterBaseCharacteristic pushDamageBonus;
  CharacterBaseCharacteristic criticalDamageBonus;
  CharacterBaseCharacteristic neutralDamageBonus;
  CharacterBaseCharacteristic earthDamageBonus;
  CharacterBaseCharacteristic waterDamageBonus;
  CharacterBaseCharacteristic airDamageBonus;
  CharacterBaseCharacteristic fireDamageBonus;
  CharacterBaseCharacteristic dodgePALostProbability;
  CharacterBaseCharacteristic dodgePMLostProbability;
  CharacterBaseCharacteristic neutralElementResistPercent;
  CharacterBaseCharacteristic earthElementResistPercent;
  CharacterBaseCharacteristic waterElementResistPercent;
  CharacterBaseCharacteristic airElementResistPercent;
  CharacterBaseCharacteristic fireElementResistPercent;
  CharacterBaseCharacteristic neutralElementReduction;
  CharacterBaseCharacteristic earthElementReduction;
  CharacterBaseCharacteristic waterElementReduction;
  CharacterBaseCharacteristic airElementReduction;
  CharacterBaseCharacteristic fireElementReduction;
  CharacterBaseCharacteristic pushDamageReduction;
  CharacterBaseCharacteristic criticalDamageReduction;
  CharacterBaseCharacteristic pvpNeutralElementResistPercent;
  CharacterBaseCharacteristic pvpEarthElementResistPercent;
  CharacterBaseCharacteristic pvpWaterElementResistPercent;
  CharacterBaseCharacteristic pvpAirElementResistPercent;
  CharacterBaseCharacteristic pvpFireElementResistPercent;
  CharacterBaseCharacteristic pvpNeutralElementReduction;
  CharacterBaseCharacteristic pvpEarthElementReduction;
  CharacterBaseCharacteristic pvpWaterElementReduction;
  CharacterBaseCharacteristic pvpAirElementReduction;
  CharacterBaseCharacteristic pvpFireElementReduction;
  QList<CharacterSpellModification> spellModifications;
  uint probationTime;
};

#endif // CHARACTERCHARACTERISTICSINFORMATIONS_H