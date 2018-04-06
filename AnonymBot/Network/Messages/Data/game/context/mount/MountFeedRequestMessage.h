#ifndef MOUNTFEEDREQUESTMESSAGE_H
#define MOUNTFEEDREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountFeedRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountFeedRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountFeedRequestMessage(Reader *param1);
  MountFeedRequestMessage();

  uint mountUid;
  int mountLocation;
  uint mountFoodUid;
  uint quantity;
};

#endif // MOUNTFEEDREQUESTMESSAGE_H