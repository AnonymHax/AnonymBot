#ifndef HUMANOPTIONALLIANCE_H
#define HUMANOPTIONALLIANCE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionAlliance : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionAlliance(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionAlliance(Reader *param1);
  HumanOptionAlliance();
  bool operator==(const HumanOptionAlliance &compared);

  QSharedPointer<AllianceInformations> allianceInformations;
  uint aggressable;
};

#endif // HUMANOPTIONALLIANCE_H