#ifndef HOUSETOSELLFILTERMESSAGE_H
#define HOUSETOSELLFILTERMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseToSellFilterMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseToSellFilterMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseToSellFilterMessage(Reader *param1);
  HouseToSellFilterMessage();

  int areaId;
  uint atLeastNbRoom;
  uint atLeastNbChest;
  uint skillRequested;
  uint maxPrice;
};

#endif // HOUSETOSELLFILTERMESSAGE_H