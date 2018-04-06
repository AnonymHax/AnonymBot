#ifndef NOTIFICATIONUPDATEFLAGMESSAGE_H
#define NOTIFICATIONUPDATEFLAGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NotificationUpdateFlagMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NotificationUpdateFlagMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NotificationUpdateFlagMessage(Reader *param1);
  NotificationUpdateFlagMessage();

  uint index;
};

#endif // NOTIFICATIONUPDATEFLAGMESSAGE_H