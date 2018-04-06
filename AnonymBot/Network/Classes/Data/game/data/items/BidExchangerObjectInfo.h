#ifndef BIDEXCHANGEROBJECTINFO_H
#define BIDEXCHANGEROBJECTINFO_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/Data/game/data/items/effects/ObjectEffect.h"
#include "Network/Classes/ClassManager.h"

class BidExchangerObjectInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BidExchangerObjectInfo(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BidExchangerObjectInfo(Reader *param1);
  BidExchangerObjectInfo();
  bool operator==(const BidExchangerObjectInfo &compared);

  uint objectUID;
  QList<QSharedPointer<ObjectEffect>> effects;
  QList<uint> prices;
};

#endif // BIDEXCHANGEROBJECTINFO_H