#ifndef PRISMSUBAREAEMPTYINFO_H
#define PRISMSUBAREAEMPTYINFO_H

#include "Network/Classes/AbstractClass.h"

class PrismSubareaEmptyInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismSubareaEmptyInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismSubareaEmptyInfo(Reader *param1);
  PrismSubareaEmptyInfo();
  bool operator==(const PrismSubareaEmptyInfo &compared);

  uint subAreaId;
  uint allianceId;
};

#endif // PRISMSUBAREAEMPTYINFO_H