#ifndef UPDATEMOUNTBOOSTMESSAGE_H
#define UPDATEMOUNTBOOSTMESSAGE_H

#include "Network/Classes/Data/game/mount/UpdateMountBoost.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/mount/UpdateMountBoost.h"
#include "Network/Classes/ClassManager.h"

class UpdateMountBoostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateMountBoostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateMountBoostMessage(Reader *param1);
  UpdateMountBoostMessage();

  int rideId;
  QList<QSharedPointer<UpdateMountBoost>> boostToUpdateList;
};

#endif // UPDATEMOUNTBOOSTMESSAGE_H