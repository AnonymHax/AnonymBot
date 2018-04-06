#ifndef LEAVEDIALOGMESSAGE_H
#define LEAVEDIALOGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LeaveDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LeaveDialogMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LeaveDialogMessage(Reader *param1);
  LeaveDialogMessage();

  uint dialogType;
};

#endif // LEAVEDIALOGMESSAGE_H