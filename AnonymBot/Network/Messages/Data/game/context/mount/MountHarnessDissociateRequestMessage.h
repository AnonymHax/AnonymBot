#ifndef MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H
#define MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class MountHarnessDissociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MountHarnessDissociateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MountHarnessDissociateRequestMessage(Reader *param1);
  MountHarnessDissociateRequestMessage();
};

#endif // MOUNTHARNESSDISSOCIATEREQUESTMESSAGE_H