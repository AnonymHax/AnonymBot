#ifndef PADDOCKABANDONNEDINFORMATIONS_H
#define PADDOCKABANDONNEDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/paddock/PaddockBuyableInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockBuyableInformations.h"

class PaddockAbandonnedInformations : public PaddockBuyableInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockAbandonnedInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockAbandonnedInformations(Reader *param1);
  PaddockAbandonnedInformations();
  bool operator==(const PaddockAbandonnedInformations &compared);

  int guildId;
};

#endif // PADDOCKABANDONNEDINFORMATIONS_H