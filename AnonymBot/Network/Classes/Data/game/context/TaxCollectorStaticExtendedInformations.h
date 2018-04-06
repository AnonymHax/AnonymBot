#ifndef TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H
#define TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/TaxCollectorStaticInformations.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class TaxCollectorStaticExtendedInformations : public TaxCollectorStaticInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorStaticExtendedInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorStaticExtendedInformations(Reader *param1);
  TaxCollectorStaticExtendedInformations();
  bool operator==(const TaxCollectorStaticExtendedInformations &compared);

  QSharedPointer<AllianceInformations> allianceIdentity;
};

#endif // TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H