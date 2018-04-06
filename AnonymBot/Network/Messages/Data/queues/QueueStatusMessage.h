#ifndef QUEUESTATUSMESSAGE_H
#define QUEUESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QueueStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QueueStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QueueStatusMessage(Reader *param1);
  QueueStatusMessage();

  uint position;
  uint total;
};

#endif // QUEUESTATUSMESSAGE_H