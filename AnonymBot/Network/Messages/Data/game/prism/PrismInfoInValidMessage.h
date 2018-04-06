#ifndef PRISMINFOINVALIDMESSAGE_H
#define PRISMINFOINVALIDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismInfoInValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismInfoInValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismInfoInValidMessage(Reader *param1);
  PrismInfoInValidMessage();

  uint reason;
};

#endif // PRISMINFOINVALIDMESSAGE_H