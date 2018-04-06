#ifndef HOUSEGUILDRIGHTSVIEWMESSAGE_H
#define HOUSEGUILDRIGHTSVIEWMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseGuildRightsViewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseGuildRightsViewMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseGuildRightsViewMessage(Reader *param1);
  HouseGuildRightsViewMessage();
};

#endif // HOUSEGUILDRIGHTSVIEWMESSAGE_H