#ifndef BASICSTATMESSAGE_H
#define BASICSTATMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicStatMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicStatMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicStatMessage(Reader *param1);
  BasicStatMessage();

  double timeSpent;
  uint statId;
};

#endif // BASICSTATMESSAGE_H