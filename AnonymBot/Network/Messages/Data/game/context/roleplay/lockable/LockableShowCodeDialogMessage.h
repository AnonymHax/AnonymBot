#ifndef LOCKABLESHOWCODEDIALOGMESSAGE_H
#define LOCKABLESHOWCODEDIALOGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LockableShowCodeDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LockableShowCodeDialogMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LockableShowCodeDialogMessage(Reader *param1);
  LockableShowCodeDialogMessage();

  bool changeOrUse;
  uint codeSize;
};

#endif // LOCKABLESHOWCODEDIALOGMESSAGE_H