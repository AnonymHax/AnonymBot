#ifndef HOUSEINFORMATIONSFORSELL_H
#define HOUSEINFORMATIONSFORSELL_H

#include "Network/Classes/AbstractClass.h"

class HouseInformationsForSell : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseInformationsForSell(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseInformationsForSell(Reader *param1);
  HouseInformationsForSell();
  bool operator==(const HouseInformationsForSell &compared);

  uint modelId;
  QString ownerName;
  bool ownerConnected;
  int worldX;
  int worldY;
  uint subAreaId;
  int nbRoom;
  int nbChest;
  QList<int> skillListIds;
  bool isLocked;
  uint price;
};

#endif // HOUSEINFORMATIONSFORSELL_H