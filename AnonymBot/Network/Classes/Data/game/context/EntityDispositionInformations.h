#ifndef ENTITYDISPOSITIONINFORMATIONS_H
#define ENTITYDISPOSITIONINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class EntityDispositionInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_EntityDispositionInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_EntityDispositionInformations(Reader *param1);
  EntityDispositionInformations();
  bool operator==(const EntityDispositionInformations &compared);

  int cellId;
  uint direction;
};

#endif // ENTITYDISPOSITIONINFORMATIONS_H