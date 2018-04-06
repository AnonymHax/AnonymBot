#ifndef ALLIANCEPRISMINFORMATION_H
#define ALLIANCEPRISMINFORMATION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Classes/Data/game/prism/PrismInformation.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"

class AlliancePrismInformation : public PrismInformation
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlliancePrismInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlliancePrismInformation(Reader *param1);
  AlliancePrismInformation();
  bool operator==(const AlliancePrismInformation &compared);

  QSharedPointer<AllianceInformations> alliance;
};

#endif // ALLIANCEPRISMINFORMATION_H