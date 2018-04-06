#ifndef IGNOREDONLINEINFORMATIONS_H
#define IGNOREDONLINEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Classes/Data/game/friend/IgnoredInformations.h"
#include "Network/Enum/Data/PlayableBreedEnum.h"

class IgnoredOnlineInformations : public IgnoredInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredOnlineInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredOnlineInformations(Reader *param1);
  IgnoredOnlineInformations();
  bool operator==(const IgnoredOnlineInformations &compared);

  double playerId;
  QString playerName;
  int breed;
  bool sex;
};

#endif // IGNOREDONLINEINFORMATIONS_H