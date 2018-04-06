#ifndef GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H
#define GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/AlternativeMonstersInGroupLightInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AlternativeMonstersInGroupLightInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GroupMonsterStaticInformations.h"

class GroupMonsterStaticInformationsWithAlternatives : public GroupMonsterStaticInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GroupMonsterStaticInformationsWithAlternatives(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GroupMonsterStaticInformationsWithAlternatives(Reader *param1);
  GroupMonsterStaticInformationsWithAlternatives();
  bool operator==(const GroupMonsterStaticInformationsWithAlternatives &compared);

  QList<AlternativeMonstersInGroupLightInformations> alternatives;
};

#endif // GROUPMONSTERSTATICINFORMATIONSWITHALTERNATIVES_H