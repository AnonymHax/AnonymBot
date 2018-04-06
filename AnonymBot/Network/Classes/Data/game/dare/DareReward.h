#ifndef DAREREWARD_H
#define DAREREWARD_H

#include "Network/Classes/AbstractClass.h"

class DareReward : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareReward(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareReward(Reader *param1);
  DareReward();
  bool operator==(const DareReward &compared);

  uint type;
  uint monsterId;
  uint kamas;
  double dareId;
};

#endif // DAREREWARD_H