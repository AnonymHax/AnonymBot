#ifndef JOBALLOWMULTICRAFTREQUESTMESSAGE_H
#define JOBALLOWMULTICRAFTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class JobAllowMultiCraftRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobAllowMultiCraftRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobAllowMultiCraftRequestMessage(Reader *param1);
  JobAllowMultiCraftRequestMessage();

  bool enabled;
};

#endif // JOBALLOWMULTICRAFTREQUESTMESSAGE_H