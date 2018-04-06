#ifndef HUMANOPTIONOBJECTUSE_H
#define HUMANOPTIONOBJECTUSE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionObjectUse : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionObjectUse(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionObjectUse(Reader *param1);
  HumanOptionObjectUse();
  bool operator==(const HumanOptionObjectUse &compared);

  uint delayTypeId;
  double delayEndTime;
  uint objectGID;
};

#endif // HUMANOPTIONOBJECTUSE_H