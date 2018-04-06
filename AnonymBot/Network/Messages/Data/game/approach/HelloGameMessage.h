#ifndef HELLOGAMEMESSAGE_H
#define HELLOGAMEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HelloGameMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HelloGameMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HelloGameMessage(Reader *param1);
  HelloGameMessage();
};

#endif // HELLOGAMEMESSAGE_H