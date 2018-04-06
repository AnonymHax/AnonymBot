#ifndef LOCKABLECODERESULTMESSAGE_H
#define LOCKABLECODERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LockableCodeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableCodeResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableCodeResultMessage(Reader *param1);
  LockableCodeResultMessage();

  uint result;
};

#endif // LOCKABLECODERESULTMESSAGE_H