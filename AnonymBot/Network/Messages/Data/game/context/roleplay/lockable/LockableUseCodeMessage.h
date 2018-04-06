#ifndef LOCKABLEUSECODEMESSAGE_H
#define LOCKABLEUSECODEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LockableUseCodeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableUseCodeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableUseCodeMessage(Reader *param1);
  LockableUseCodeMessage();

  QString code;
};

#endif // LOCKABLEUSECODEMESSAGE_H