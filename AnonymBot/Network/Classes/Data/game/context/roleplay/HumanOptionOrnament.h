#ifndef HUMANOPTIONORNAMENT_H
#define HUMANOPTIONORNAMENT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionOrnament : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionOrnament(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionOrnament(Reader *param1);
  HumanOptionOrnament();
  bool operator==(const HumanOptionOrnament &compared);

  uint ornamentId;
};

#endif // HUMANOPTIONORNAMENT_H