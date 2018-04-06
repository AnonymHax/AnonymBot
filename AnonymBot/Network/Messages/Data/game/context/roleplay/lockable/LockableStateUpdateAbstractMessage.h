#ifndef LOCKABLESTATEUPDATEABSTRACTMESSAGE_H
#define LOCKABLESTATEUPDATEABSTRACTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LockableStateUpdateAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableStateUpdateAbstractMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableStateUpdateAbstractMessage(Reader *param1);
  LockableStateUpdateAbstractMessage();

  bool locked;
};

#endif // LOCKABLESTATEUPDATEABSTRACTMESSAGE_H