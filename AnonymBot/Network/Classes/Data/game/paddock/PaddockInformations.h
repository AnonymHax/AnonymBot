#ifndef PADDOCKINFORMATIONS_H
#define PADDOCKINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class PaddockInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockInformations(Reader *param1);
  PaddockInformations();
  bool operator==(const PaddockInformations &compared);

  uint maxOutdoorMount;
  uint maxItems;
};

#endif // PADDOCKINFORMATIONS_H