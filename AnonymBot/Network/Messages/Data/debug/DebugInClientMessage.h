#ifndef DEBUGINCLIENTMESSAGE_H
#define DEBUGINCLIENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DebugInClientMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DebugInClientMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DebugInClientMessage(Reader *param1);
  DebugInClientMessage();

  uint level;
  QString message;
};

#endif // DEBUGINCLIENTMESSAGE_H