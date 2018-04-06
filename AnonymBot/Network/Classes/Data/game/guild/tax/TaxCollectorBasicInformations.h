#ifndef TAXCOLLECTORBASICINFORMATIONS_H
#define TAXCOLLECTORBASICINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class TaxCollectorBasicInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorBasicInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorBasicInformations(Reader *param1);
  TaxCollectorBasicInformations();
  bool operator==(const TaxCollectorBasicInformations &compared);

  uint firstNameId;
  uint lastNameId;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
};

#endif // TAXCOLLECTORBASICINFORMATIONS_H