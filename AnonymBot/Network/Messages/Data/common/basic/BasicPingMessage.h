#ifndef BASICPINGMESSAGE_H
#define BASICPINGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicPingMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicPingMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicPingMessage(Reader *param1);
  BasicPingMessage();

  bool quiet;
};

#endif // BASICPINGMESSAGE_H