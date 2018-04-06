#ifndef LEAVEDIALOGREQUESTMESSAGE_H
#define LEAVEDIALOGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LeaveDialogRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LeaveDialogRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LeaveDialogRequestMessage(Reader *param1);
  LeaveDialogRequestMessage();
};

#endif // LEAVEDIALOGREQUESTMESSAGE_H