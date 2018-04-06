#ifndef TREASUREHUNTSTEP_H
#define TREASUREHUNTSTEP_H

#include "Network/Classes/AbstractClass.h"

class TreasureHuntStep : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntStep(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntStep(Reader *param1);
  TreasureHuntStep();
  bool operator==(const TreasureHuntStep &compared);
};

#endif // TREASUREHUNTSTEP_H