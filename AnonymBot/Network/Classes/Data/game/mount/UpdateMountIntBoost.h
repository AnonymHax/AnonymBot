#ifndef UPDATEMOUNTINTBOOST_H
#define UPDATEMOUNTINTBOOST_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/mount/UpdateMountBoost.h"
#include "Network/Classes/Data/game/mount/UpdateMountBoost.h"

class UpdateMountIntBoost : public UpdateMountBoost
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateMountIntBoost(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateMountIntBoost(Reader *param1);
  UpdateMountIntBoost();
  bool operator==(const UpdateMountIntBoost &compared);

  int value;
};

#endif // UPDATEMOUNTINTBOOST_H