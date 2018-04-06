#ifndef PRISMSLISTUPDATEMESSAGE_H
#define PRISMSLISTUPDATEMESSAGE_H

#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/prism/PrismsListMessage.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"

class PrismsListUpdateMessage : public PrismsListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismsListUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismsListUpdateMessage(Reader *param1);
  PrismsListUpdateMessage();
};

#endif // PRISMSLISTUPDATEMESSAGE_H