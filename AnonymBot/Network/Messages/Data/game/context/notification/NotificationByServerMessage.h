#ifndef NOTIFICATIONBYSERVERMESSAGE_H
#define NOTIFICATIONBYSERVERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NotificationByServerMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NotificationByServerMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NotificationByServerMessage(Reader *param1);
  NotificationByServerMessage();

  uint id;
  QList<QString> parameters;
  bool forceOpen;
};

#endif // NOTIFICATIONBYSERVERMESSAGE_H