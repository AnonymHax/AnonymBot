#ifndef CLIENTKEYMESSAGE_H
#define CLIENTKEYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ClientKeyMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ClientKeyMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ClientKeyMessage(Reader *param1);
  ClientKeyMessage();

  QString key;
};

#endif // CLIENTKEYMESSAGE_H