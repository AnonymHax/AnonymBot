#ifndef HOUSEINFORMATIONSFORGUILD_H
#define HOUSEINFORMATIONSFORGUILD_H

#include "Network/Classes/AbstractClass.h"

class HouseInformationsForGuild : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseInformationsForGuild(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseInformationsForGuild(Reader *param1);
  HouseInformationsForGuild();
  bool operator==(const HouseInformationsForGuild &compared);

  uint houseId;
  uint modelId;
  QString ownerName;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QList<int> skillListIds;
  uint guildshareParams;
};

#endif // HOUSEINFORMATIONSFORGUILD_H