#ifndef FIGHTRESULTEXPERIENCEDATA_H
#define FIGHTRESULTEXPERIENCEDATA_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "Network/Classes/Data/game/context/fight/FightResultAdditionalData.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class FightResultExperienceData : public FightResultAdditionalData
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FightResultExperienceData(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FightResultExperienceData(Reader *param1);
  FightResultExperienceData();
  bool operator==(const FightResultExperienceData &compared);

  double experience;
  bool showExperience;
  double experienceLevelFloor;
  bool showExperienceLevelFloor;
  double experienceNextLevelFloor;
  bool showExperienceNextLevelFloor;
  double experienceFightDelta;
  bool showExperienceFightDelta;
  double experienceForGuild;
  bool showExperienceForGuild;
  double experienceForMount;
  bool showExperienceForMount;
  bool isIncarnationExperience;
  uint rerollExperienceMul;
};

#endif // FIGHTRESULTEXPERIENCEDATA_H