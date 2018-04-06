#ifndef HOUSELOCKFROMINSIDEREQUESTMESSAGE_H
#define HOUSELOCKFROMINSIDEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/lockable/LockableChangeCodeMessage.h"

class HouseLockFromInsideRequestMessage : public LockableChangeCodeMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseLockFromInsideRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseLockFromInsideRequestMessage(Reader *param1);
  HouseLockFromInsideRequestMessage();
};

#endif // HOUSELOCKFROMINSIDEREQUESTMESSAGE_H