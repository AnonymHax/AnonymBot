#ifndef HAVENBAGFURNITURESMESSAGE_H
#define HAVENBAGFURNITURESMESSAGE_H

#include "Network/Classes/Data/game/guild/HavenBagFurnitureInformation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/HavenBagFurnitureInformation.h"

class HavenBagFurnituresMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HavenBagFurnituresMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HavenBagFurnituresMessage(Reader *param1);
  HavenBagFurnituresMessage();

  QList<HavenBagFurnitureInformation> furnituresInfos;
};

#endif // HAVENBAGFURNITURESMESSAGE_H