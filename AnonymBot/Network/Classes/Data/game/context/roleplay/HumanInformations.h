#ifndef HUMANINFORMATIONS_H
#define HUMANINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/restriction/ActorRestrictionsInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/character/restriction/ActorRestrictionsInformations.h"
#include "Network/Classes/ClassManager.h"

class HumanInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanInformations(Reader *param1);
  HumanInformations();
  bool operator==(const HumanInformations &compared);

  ActorRestrictionsInformations restrictions;
  bool sex;
  QList<QSharedPointer<HumanOption>> options;
};

#endif // HUMANINFORMATIONS_H