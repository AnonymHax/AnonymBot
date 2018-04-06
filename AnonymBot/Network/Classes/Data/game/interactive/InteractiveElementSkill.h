#ifndef INTERACTIVEELEMENTSKILL_H
#define INTERACTIVEELEMENTSKILL_H

#include "Network/Classes/AbstractClass.h"

class InteractiveElementSkill : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveElementSkill(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveElementSkill(Reader *param1);
  InteractiveElementSkill();
  bool operator==(const InteractiveElementSkill &compared);

  uint skillId;
  uint skillInstanceUid;
};

#endif // INTERACTIVEELEMENTSKILL_H