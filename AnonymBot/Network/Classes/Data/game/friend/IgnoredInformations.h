#ifndef IGNOREDINFORMATIONS_H
#define IGNOREDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/friend/AbstractContactInformations.h"
#include "Network/Classes/Data/game/friend/AbstractContactInformations.h"

class IgnoredInformations : public AbstractContactInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IgnoredInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IgnoredInformations(Reader *param1);
  IgnoredInformations();
  bool operator==(const IgnoredInformations &compared);
};

#endif // IGNOREDINFORMATIONS_H