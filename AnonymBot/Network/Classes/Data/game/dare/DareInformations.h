#ifndef DAREINFORMATIONS_H
#define DAREINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/CharacterBasicMinimalInformations.h"
#include "Network/Classes/Data/game/dare/DareCriteria.h"
#include "Network/Classes/Data/game/character/CharacterBasicMinimalInformations.h"

class DareInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareInformations(Reader *param1);
  DareInformations();
  bool operator==(const DareInformations &compared);

  double dareId;
  CharacterBasicMinimalInformations creator;
  uint subscriptionFee;
  uint jackpot;
  uint maxCountWinners;
  double endDate;
  bool isPrivate;
  uint guildId;
  uint allianceId;
  QList<DareCriteria> criterions;
  double startDate;
};

#endif // DAREINFORMATIONS_H