#ifndef KROSMASTERTRANSFERREQUESTMESSAGE_H
#define KROSMASTERTRANSFERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterTransferRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterTransferRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterTransferRequestMessage(Reader *param1);
  KrosmasterTransferRequestMessage();

  QString uid;
};

#endif // KROSMASTERTRANSFERREQUESTMESSAGE_H