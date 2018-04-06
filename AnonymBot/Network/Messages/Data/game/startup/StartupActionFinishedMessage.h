#ifndef STARTUPACTIONFINISHEDMESSAGE_H
#define STARTUPACTIONFINISHEDMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class StartupActionFinishedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StartupActionFinishedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StartupActionFinishedMessage(Reader *param1);
  StartupActionFinishedMessage();

  bool success;
  uint actionId;
  bool automaticAction;
};

#endif // STARTUPACTIONFINISHEDMESSAGE_H