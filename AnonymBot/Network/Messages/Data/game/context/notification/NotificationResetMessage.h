#ifndef NOTIFICATIONRESETMESSAGE_H
#define NOTIFICATIONRESETMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NotificationResetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NotificationResetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NotificationResetMessage(Reader *param1);
  NotificationResetMessage();
};

#endif // NOTIFICATIONRESETMESSAGE_H