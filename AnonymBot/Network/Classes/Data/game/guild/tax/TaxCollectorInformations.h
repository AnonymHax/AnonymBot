#ifndef TAXCOLLECTORINFORMATIONS_H
#define TAXCOLLECTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/guild/tax/AdditionalTaxCollectorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/guild/tax/AdditionalTaxCollectorInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/ClassManager.h"

class TaxCollectorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorInformations(Reader *param1);
  TaxCollectorInformations();
  bool operator==(const TaxCollectorInformations &compared);

  int uniqueId;
  uint firtNameId;
  uint lastNameId;
  AdditionalTaxCollectorInformations additionalInfos;
  int worldX;
  int worldY;
  uint subAreaId;
  uint state;
  QSharedPointer<EntityLook> look;
  QList<QSharedPointer<TaxCollectorComplementaryInformations>> complements;
};

#endif // TAXCOLLECTORINFORMATIONS_H