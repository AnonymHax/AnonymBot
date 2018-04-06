#ifndef ACCOUNTHOUSEINFORMATIONS_H
#define ACCOUNTHOUSEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class AccountHouseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AccountHouseInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AccountHouseInformations(Reader *param1);
  AccountHouseInformations();
  bool operator==(const AccountHouseInformations &compared);

  uint houseId;
  uint modelId;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
};

#endif // ACCOUNTHOUSEINFORMATIONS_H