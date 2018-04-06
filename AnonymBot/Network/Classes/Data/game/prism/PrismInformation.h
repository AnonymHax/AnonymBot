#ifndef PRISMINFORMATION_H
#define PRISMINFORMATION_H

#include "Network/Classes/AbstractClass.h"

class PrismInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismInformation(Reader *param1);
  PrismInformation();
  bool operator==(const PrismInformation &compared);

  uint typeId;
  uint state;
  uint nextVulnerabilityDate;
  uint placementDate;
  uint rewardTokenCount;
};

#endif // PRISMINFORMATION_H