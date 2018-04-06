#ifndef HOUSETOSELLLISTREQUESTMESSAGE_H
#define HOUSETOSELLLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseToSellListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseToSellListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseToSellListRequestMessage(Reader *param1);
  HouseToSellListRequestMessage();

  uint pageIndex;
};

#endif // HOUSETOSELLLISTREQUESTMESSAGE_H