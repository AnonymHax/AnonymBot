#ifndef TAXCOLLECTORFIGHTERSINFORMATION_H
#define TAXCOLLECTORFIGHTERSINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"

class TaxCollectorFightersInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorFightersInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorFightersInformation(Reader *param1);
  TaxCollectorFightersInformation();
  bool operator==(const TaxCollectorFightersInformation &compared);

  int collectorId;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> allyCharactersInformations;
  QList<QSharedPointer<CharacterMinimalPlusLookInformations>> enemyCharactersInformations;
};

#endif // TAXCOLLECTORFIGHTERSINFORMATION_H