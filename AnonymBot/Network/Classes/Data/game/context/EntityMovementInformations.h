#ifndef ENTITYMOVEMENTINFORMATIONS_H
#define ENTITYMOVEMENTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class EntityMovementInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EntityMovementInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EntityMovementInformations(Reader *param1);
  EntityMovementInformations();
  bool operator==(const EntityMovementInformations &compared);

  int id;
  QList<int> steps;
};

#endif // ENTITYMOVEMENTINFORMATIONS_H