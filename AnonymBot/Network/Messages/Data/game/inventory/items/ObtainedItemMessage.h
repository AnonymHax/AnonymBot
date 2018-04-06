#ifndef OBTAINEDITEMMESSAGE_H
#define OBTAINEDITEMMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObtainedItemMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObtainedItemMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObtainedItemMessage(Reader *param1);
  ObtainedItemMessage();

  uint genericId;
  uint baseQuantity;
};

#endif // OBTAINEDITEMMESSAGE_H