#ifndef TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H
#define TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorComplementaryInformations.h"
#include "Network/Classes/Data/game/fight/ProtectedEntityWaitingForHelpInfo.h"

class TaxCollectorWaitingForHelpInformations : public TaxCollectorComplementaryInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorWaitingForHelpInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorWaitingForHelpInformations(Reader *param1);
  TaxCollectorWaitingForHelpInformations();
  bool operator==(const TaxCollectorWaitingForHelpInformations &compared);

  ProtectedEntityWaitingForHelpInfo waitingForHelpInfo;
};

#endif // TAXCOLLECTORWAITINGFORHELPINFORMATIONS_H