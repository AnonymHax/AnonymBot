#ifndef SKILLACTIONDESCRIPTIONTIMED_H
#define SKILLACTIONDESCRIPTIONTIMED_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"

class SkillActionDescriptionTimed : public SkillActionDescription
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SkillActionDescriptionTimed(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SkillActionDescriptionTimed(Reader *param1);
  SkillActionDescriptionTimed();
  bool operator==(const SkillActionDescriptionTimed &compared);

  uint time;
};

#endif // SKILLACTIONDESCRIPTIONTIMED_H