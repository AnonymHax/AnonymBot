#ifndef PADDOCKBUYABLEINFORMATIONS_H
#define PADDOCKBUYABLEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"
#include "Network/Classes/Data/game/paddock/PaddockInformations.h"

class PaddockBuyableInformations : public PaddockInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockBuyableInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockBuyableInformations(Reader *param1);
  PaddockBuyableInformations();
  bool operator==(const PaddockBuyableInformations &compared);

  uint price;
  bool locked;
};

#endif // PADDOCKBUYABLEINFORMATIONS_H