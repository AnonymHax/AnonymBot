#ifndef SKILLACTIONDESCRIPTIONCRAFT_H
#define SKILLACTIONDESCRIPTIONCRAFT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"
#include "Network/Classes/Data/game/interactive/skill/SkillActionDescription.h"

class SkillActionDescriptionCraft : public SkillActionDescription
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SkillActionDescriptionCraft(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SkillActionDescriptionCraft(Reader *param1);
  SkillActionDescriptionCraft();
  bool operator==(const SkillActionDescriptionCraft &compared);

  uint probability;
};

#endif // SKILLACTIONDESCRIPTIONCRAFT_H