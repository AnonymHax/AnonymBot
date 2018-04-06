#ifndef PADDOCKTOSELLLISTMESSAGE_H
#define PADDOCKTOSELLLISTMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockInformationsForSell.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockInformationsForSell.h"

class PaddockToSellListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockToSellListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockToSellListMessage(Reader *param1);
  PaddockToSellListMessage();

  uint pageIndex;
  uint totalPage;
  QList<PaddockInformationsForSell> paddockList;
};

#endif // PADDOCKTOSELLLISTMESSAGE_H