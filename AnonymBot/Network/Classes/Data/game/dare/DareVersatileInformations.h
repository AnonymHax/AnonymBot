#ifndef DAREVERSATILEINFORMATIONS_H
#define DAREVERSATILEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class DareVersatileInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareVersatileInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareVersatileInformations(Reader *param1);
  DareVersatileInformations();
  bool operator==(const DareVersatileInformations &compared);

  double dareId;
  uint countEntrants;
  uint countWinners;
};

#endif // DAREVERSATILEINFORMATIONS_H