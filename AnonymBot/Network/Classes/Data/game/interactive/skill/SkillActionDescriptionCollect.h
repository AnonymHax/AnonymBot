#ifndef SKILLACTIONDESCRIPTIONCOLLECT_H
#define SKILLACTIONDESCRIPTIONCOLLECT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescriptionTimed.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescriptionTimed.h"

class SkillActionDescriptionCollect : public SkillActionDescriptionTimed
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SkillActionDescriptionCollect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SkillActionDescriptionCollect(Reader *param1);
  SkillActionDescriptionCollect();
  bool operator==(const SkillActionDescriptionCollect &compared);

  uint min;
  uint max;
};

#endif // SKILLACTIONDESCRIPTIONCOLLECT_H