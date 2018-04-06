#ifndef PRISMFIGHTREMOVEDMESSAGE_H
#define PRISMFIGHTREMOVEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightRemovedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightRemovedMessage(Reader *param1);
  PrismFightRemovedMessage();

  uint subAreaId;
};

#endif // PRISMFIGHTREMOVEDMESSAGE_H