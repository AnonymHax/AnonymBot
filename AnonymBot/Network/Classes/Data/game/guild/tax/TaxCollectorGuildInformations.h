#ifndef TAXCOLLECTORGUILDINFORMATIONS_H
#define TAXCOLLECTORGUILDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"

class TaxCollectorGuildInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorGuildInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorGuildInformations(Reader *param1);
  TaxCollectorGuildInformations();
  bool operator==(const TaxCollectorGuildInformations &compared);

  QSharedPointer<BasicGuildInformations> guild;
};

#endif // TAXCOLLECTORGUILDINFORMATIONS_H