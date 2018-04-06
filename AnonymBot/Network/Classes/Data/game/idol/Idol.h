#ifndef IDOL_H
#define IDOL_H

#include "Network/Classes/AbstractClass.h"

class Idol : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_Idol(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_Idol(Reader *param1);
  Idol();
  bool operator==(const Idol &compared);

  uint id;
  uint xpBonusPercent;
  uint dropBonusPercent;
};

#endif // IDOL_H