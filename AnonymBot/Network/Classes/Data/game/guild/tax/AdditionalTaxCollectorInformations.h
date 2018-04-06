#ifndef ADDITIONALTAXCOLLECTORINFORMATIONS_H
#define ADDITIONALTAXCOLLECTORINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class AdditionalTaxCollectorInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AdditionalTaxCollectorInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AdditionalTaxCollectorInformations(Reader *param1);
  AdditionalTaxCollectorInformations();
  bool operator==(const AdditionalTaxCollectorInformations &compared);

  QString collectorCallerName;
  uint date;
};

#endif // ADDITIONALTAXCOLLECTORINFORMATIONS_H