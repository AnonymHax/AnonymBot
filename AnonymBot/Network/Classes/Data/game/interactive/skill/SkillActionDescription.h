#ifndef SKILLACTIONDESCRIPTION_H
#define SKILLACTIONDESCRIPTION_H

#include "Network/Classes/AbstractClass.h"

class SkillActionDescription : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SkillActionDescription(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SkillActionDescription(Reader *param1);
  SkillActionDescription();
  bool operator==(const SkillActionDescription &compared);

  uint skillId;
};

#endif // SKILLACTIONDESCRIPTION_H