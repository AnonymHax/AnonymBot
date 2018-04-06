#ifndef PRISMINFOCLOSEMESSAGE_H
#define PRISMINFOCLOSEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismInfoCloseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismInfoCloseMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismInfoCloseMessage(Reader *param1);
  PrismInfoCloseMessage();
};

#endif // PRISMINFOCLOSEMESSAGE_H