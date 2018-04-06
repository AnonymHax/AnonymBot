#ifndef HAVENBAGFURNITUREINFORMATION_H
#define HAVENBAGFURNITUREINFORMATION_H

#include "Network/Classes/AbstractClass.h"

class HavenBagFurnitureInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HavenBagFurnitureInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HavenBagFurnitureInformation(Reader *param1);
  HavenBagFurnitureInformation();
  bool operator==(const HavenBagFurnitureInformation &compared);

  uint cellId;
  int funitureId;
  uint orientation;
};

#endif // HAVENBAGFURNITUREINFORMATION_H