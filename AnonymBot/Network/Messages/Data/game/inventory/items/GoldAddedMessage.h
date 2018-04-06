#ifndef GOLDADDEDMESSAGE_H
#define GOLDADDEDMESSAGE_H

#include "Network/Classes/Data/game/data/items/GoldItem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/GoldItem.h"

class GoldAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GoldAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GoldAddedMessage(Reader *param1);
  GoldAddedMessage();

  GoldItem gold;
};

#endif // GOLDADDEDMESSAGE_H