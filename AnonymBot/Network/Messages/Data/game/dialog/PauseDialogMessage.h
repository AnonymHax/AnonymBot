#ifndef PAUSEDIALOGMESSAGE_H
#define PAUSEDIALOGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PauseDialogMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PauseDialogMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PauseDialogMessage(Reader *param1);
  PauseDialogMessage();

  uint dialogType;
};

#endif // PAUSEDIALOGMESSAGE_H