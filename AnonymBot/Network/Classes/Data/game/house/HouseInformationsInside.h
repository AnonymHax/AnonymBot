#ifndef HOUSEINFORMATIONSINSIDE_H
#define HOUSEINFORMATIONSINSIDE_H

#include "Network/Classes/AbstractClass.h"

class HouseInformationsInside : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseInformationsInside(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseInformationsInside(Reader *param1);
  HouseInformationsInside();
  bool operator==(const HouseInformationsInside &compared);

  uint houseId;
  uint modelId;
  int ownerId;
  QString ownerName;
  int worldX;
  int worldY;
  uint price;
  bool isLocked;
};

#endif // HOUSEINFORMATIONSINSIDE_H