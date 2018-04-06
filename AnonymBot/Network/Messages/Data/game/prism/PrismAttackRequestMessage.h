#ifndef PRISMATTACKREQUESTMESSAGE_H
#define PRISMATTACKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismAttackRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismAttackRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismAttackRequestMessage(Reader *param1);
  PrismAttackRequestMessage();
};

#endif // PRISMATTACKREQUESTMESSAGE_H