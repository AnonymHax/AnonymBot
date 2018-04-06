#ifndef PRISMFIGHTERSINFORMATION_H
#define PRISMFIGHTERSINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"

class PrismFightersInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightersInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightersInformation(Reader *param1);
  PrismFightersInformation();
  bool operator==(const PrismFightersInformation &compared);

  uint subAreaId;
  ProtectedEntityWaitingForHelpInfo waitingForHelpInfo;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> allyCharactersInformations;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> enemyCharactersInformations;
};

#endif // PRISMFIGHTERSINFORMATION_H