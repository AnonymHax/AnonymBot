#ifndef MONSTERINGROUPLIGHTINFORMATIONS_H
#define MONSTERINGROUPLIGHTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class MonsterInGroupLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MonsterInGroupLightInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MonsterInGroupLightInformations(Reader *param1);
  MonsterInGroupLightInformations();
  bool operator==(const MonsterInGroupLightInformations &compared);

  int creatureGenericId;
  uint grade;
};

#endif // MONSTERINGROUPLIGHTINFORMATIONS_H