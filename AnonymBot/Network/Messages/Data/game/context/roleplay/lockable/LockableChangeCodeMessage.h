#ifndef LOCKABLECHANGECODEMESSAGE_H
#define LOCKABLECHANGECODEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LockableChangeCodeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableChangeCodeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableChangeCodeMessage(Reader *param1);
  LockableChangeCodeMessage();

  QString code;
};

#endif // LOCKABLECHANGECODEMESSAGE_H