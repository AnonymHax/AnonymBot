#ifndef HOUSEINFORMATIONS_H
#define HOUSEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class HouseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseInformations(Reader *param1);
  HouseInformations();
  bool operator==(const HouseInformations &compared);

  uint houseId;
  QList<uint> doorsOnMap;
  QString ownerName;
  bool isOnSale;
  bool isSaleLocked;
  uint modelId;
};

#endif // HOUSEINFORMATIONS_H