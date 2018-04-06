#ifndef NOTIFICATIONLISTMESSAGE_H
#define NOTIFICATIONLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NotificationListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NotificationListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NotificationListMessage(Reader *param1);
  NotificationListMessage();

  QList<int> flags;
};

#endif // NOTIFICATIONLISTMESSAGE_H