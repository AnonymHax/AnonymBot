#ifndef UPDATEMOUNTBOOST_H
#define UPDATEMOUNTBOOST_H

#include "Network/Classes/AbstractClass.h"

class UpdateMountBoost : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateMountBoost(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateMountBoost(Reader *param1);
  UpdateMountBoost();
  bool operator==(const UpdateMountBoost &compared);

  uint type;
};

#endif // UPDATEMOUNTBOOST_H