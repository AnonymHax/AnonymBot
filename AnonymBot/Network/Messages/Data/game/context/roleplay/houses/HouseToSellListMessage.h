#ifndef HOUSETOSELLLISTMESSAGE_H
#define HOUSETOSELLLISTMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformationsForSell.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/HouseInformationsForSell.h"

class HouseToSellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseToSellListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseToSellListMessage(Reader *param1);
  HouseToSellListMessage();

  uint pageIndex;
  uint totalPage;
  QList<HouseInformationsForSell> houseList;
};

#endif // HOUSETOSELLLISTMESSAGE_H