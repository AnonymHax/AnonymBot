#ifndef PRISMSLISTREGISTERMESSAGE_H
#define PRISMSLISTREGISTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismsListRegisterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismsListRegisterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismsListRegisterMessage(Reader *param1);
  PrismsListRegisterMessage();

  uint listen;
};

#endif // PRISMSLISTREGISTERMESSAGE_H