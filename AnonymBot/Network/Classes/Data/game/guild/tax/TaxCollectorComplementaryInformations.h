#ifndef TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H
#define TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class TaxCollectorComplementaryInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorComplementaryInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorComplementaryInformations(Reader *param1);
  TaxCollectorComplementaryInformations();
  bool operator==(const TaxCollectorComplementaryInformations &compared);
};

#endif // TAXCOLLECTORCOMPLEMENTARYINFORMATIONS_H