#ifndef BASICPONGMESSAGE_H
#define BASICPONGMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicPongMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicPongMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicPongMessage(Reader *param1);
  BasicPongMessage();

  bool quiet;
};

#endif // BASICPONGMESSAGE_H