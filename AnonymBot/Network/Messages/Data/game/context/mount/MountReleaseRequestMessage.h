#ifndef MOUNTRELEASEREQUESTMESSAGE_H
#define MOUNTRELEASEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountReleaseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountReleaseRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountReleaseRequestMessage(Reader *param1);
  MountReleaseRequestMessage();
};

#endif // MOUNTRELEASEREQUESTMESSAGE_H