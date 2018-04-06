#ifndef SELECTEDSERVERREFUSEDMESSAGE_H
#define SELECTEDSERVERREFUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SelectedServerRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SelectedServerRefusedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SelectedServerRefusedMessage(Reader *param1);
  SelectedServerRefusedMessage();

  uint serverId;
  uint error;
  uint serverStatus;
};

#endif // SELECTEDSERVERREFUSEDMESSAGE_H