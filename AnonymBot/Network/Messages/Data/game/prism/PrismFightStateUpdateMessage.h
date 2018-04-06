#ifndef PRISMFIGHTSTATEUPDATEMESSAGE_H
#define PRISMFIGHTSTATEUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PrismFightStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightStateUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightStateUpdateMessage(Reader *param1);
  PrismFightStateUpdateMessage();

  uint state;
};

#endif // PRISMFIGHTSTATEUPDATEMESSAGE_H