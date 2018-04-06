#ifndef TAXCOLLECTORLOOTINFORMATIONS_H
#define TAXCOLLECTORLOOTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"

class TaxCollectorLootInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorLootInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorLootInformations(Reader *param1);
  TaxCollectorLootInformations();
  bool operator==(const TaxCollectorLootInformations &compared);

  uint kamas;
  double experience;
  uint pods;
  uint itemsValue;
};

#endif // TAXCOLLECTORLOOTINFORMATIONS_H