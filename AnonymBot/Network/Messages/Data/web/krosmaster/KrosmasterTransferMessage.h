#ifndef KROSMASTERTRANSFERMESSAGE_H
#define KROSMASTERTRANSFERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterTransferMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterTransferMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterTransferMessage(Reader *param1);
  KrosmasterTransferMessage();

  QString uid;
  uint failure;
};

#endif // KROSMASTERTRANSFERMESSAGE_H