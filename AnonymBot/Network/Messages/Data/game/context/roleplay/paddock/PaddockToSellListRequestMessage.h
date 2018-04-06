#ifndef PADDOCKTOSELLLISTREQUESTMESSAGE_H
#define PADDOCKTOSELLLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class PaddockToSellListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PaddockToSellListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PaddockToSellListRequestMessage(Reader *param1);
  PaddockToSellListRequestMessage();

  uint pageIndex;
};

#endif // PADDOCKTOSELLLISTREQUESTMESSAGE_H