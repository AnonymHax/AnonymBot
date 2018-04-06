#ifndef HOUSEGUILDSHAREREQUESTMESSAGE_H
#define HOUSEGUILDSHAREREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HouseGuildShareRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseGuildShareRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseGuildShareRequestMessage(Reader *param1);
  HouseGuildShareRequestMessage();

  bool enable;
  uint rights;
};

#endif // HOUSEGUILDSHAREREQUESTMESSAGE_H