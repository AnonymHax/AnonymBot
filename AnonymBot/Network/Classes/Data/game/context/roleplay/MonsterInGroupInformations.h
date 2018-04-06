#ifndef MONSTERINGROUPINFORMATIONS_H
#define MONSTERINGROUPINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class MonsterInGroupInformations : public MonsterInGroupLightInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MonsterInGroupInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MonsterInGroupInformations(Reader *param1);
  MonsterInGroupInformations();
  bool operator==(const MonsterInGroupInformations &compared);

  QSharedPointer<EntityLook> look;
};

#endif // MONSTERINGROUPINFORMATIONS_H