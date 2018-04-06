#ifndef CLIENTUIOPENEDMESSAGE_H
#define CLIENTUIOPENEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ClientUIOpenedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ClientUIOpenedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ClientUIOpenedMessage(Reader *param1);
  ClientUIOpenedMessage();

  uint type;
};

#endif // CLIENTUIOPENEDMESSAGE_H