#ifndef GROUPMONSTERSTATICINFORMATIONS_H
#define GROUPMONSTERSTATICINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/MonsterInGroupLightInformations.h"
#include "Network/Classes/Data/game/context/roleplay/MonsterInGroupInformations.h"

class GroupMonsterStaticInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GroupMonsterStaticInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GroupMonsterStaticInformations(Reader *param1);
  GroupMonsterStaticInformations();
  bool operator==(const GroupMonsterStaticInformations &compared);

  MonsterInGroupLightInformations mainCreatureLightInfos;
  QList<QSharedPointer<MonsterInGroupInformations>> underlings;
};

#endif // GROUPMONSTERSTATICINFORMATIONS_H