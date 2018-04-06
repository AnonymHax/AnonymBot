#ifndef CLIENTUIOPENEDBYOBJECTMESSAGE_H
#define CLIENTUIOPENEDBYOBJECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/ui/ClientUIOpenedMessage.h"

class ClientUIOpenedByObjectMessage : public ClientUIOpenedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ClientUIOpenedByObjectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ClientUIOpenedByObjectMessage(Reader *param1);
  ClientUIOpenedByObjectMessage();

  uint uid;
};

#endif // CLIENTUIOPENEDBYOBJECTMESSAGE_H