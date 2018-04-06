#ifndef TREASUREHUNTFLAG_H
#define TREASUREHUNTFLAG_H

#include "Network/Classes/AbstractClass.h"

class TreasureHuntFlag : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntFlag(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntFlag(Reader *param1);
  TreasureHuntFlag();
  bool operator==(const TreasureHuntFlag &compared);

  int mapId;
  uint state;
};

#endif // TREASUREHUNTFLAG_H