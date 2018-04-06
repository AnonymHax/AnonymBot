#ifndef HUMANOPTIONSKILLUSE_H
#define HUMANOPTIONSKILLUSE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionSkillUse : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionSkillUse(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionSkillUse(Reader *param1);
  HumanOptionSkillUse();
  bool operator==(const HumanOptionSkillUse &compared);

  uint elementId;
  uint skillId;
  double skillEndTime;
};

#endif // HUMANOPTIONSKILLUSE_H