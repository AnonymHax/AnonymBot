#ifndef TAXCOLLECTORMOVEMENT_H
#define TAXCOLLECTORMOVEMENT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorBasicInformations.h"

class TaxCollectorMovement : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorMovement(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorMovement(Reader *param1);
  TaxCollectorMovement();
  bool operator==(const TaxCollectorMovement &compared);

  uint movementType;
  TaxCollectorBasicInformations basicInfos;
  double playerId;
  QString playerName;
};

#endif // TAXCOLLECTORMOVEMENT_H