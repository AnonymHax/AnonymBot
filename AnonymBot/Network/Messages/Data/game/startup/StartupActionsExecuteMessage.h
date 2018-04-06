#ifndef STARTUPACTIONSEXECUTEMESSAGE_H
#define STARTUPACTIONSEXECUTEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StartupActionsExecuteMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionsExecuteMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionsExecuteMessage(Reader *param1);
  StartupActionsExecuteMessage();
};

#endif // STARTUPACTIONSEXECUTEMESSAGE_H