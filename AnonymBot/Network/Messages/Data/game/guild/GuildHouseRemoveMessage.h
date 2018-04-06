#ifndef GUILDHOUSEREMOVEMESSAGE_H
#define GUILDHOUSEREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildHouseRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildHouseRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildHouseRemoveMessage(Reader *param1);
  GuildHouseRemoveMessage();

  uint houseId;
};

#endif // GUILDHOUSEREMOVEMESSAGE_H