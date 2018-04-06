#ifndef INTERACTIVEELEMENTNAMEDSKILL_H
#define INTERACTIVEELEMENTNAMEDSKILL_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementSkill.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementSkill.h"

class InteractiveElementNamedSkill : public InteractiveElementSkill
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveElementNamedSkill(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveElementNamedSkill(Reader *param1);
  InteractiveElementNamedSkill();
  bool operator==(const InteractiveElementNamedSkill &compared);

  uint nameId;
};

#endif // INTERACTIVEELEMENTNAMEDSKILL_H