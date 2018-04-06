#ifndef HELLOCONNECTMESSAGE_H
#define HELLOCONNECTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HelloConnectMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HelloConnectMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HelloConnectMessage(Reader *param1);
  HelloConnectMessage();

  QString salt;
  QList<int> key;
};

#endif // HELLOCONNECTMESSAGE_H