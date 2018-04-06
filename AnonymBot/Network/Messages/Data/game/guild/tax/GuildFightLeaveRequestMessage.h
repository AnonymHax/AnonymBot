#ifndef GUILDFIGHTLEAVEREQUESTMESSAGE_H
#define GUILDFIGHTLEAVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFightLeaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightLeaveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightLeaveRequestMessage(Reader *param1);
  GuildFightLeaveRequestMessage();

  uint taxCollectorId;
  double characterId;
};

#endif // GUILDFIGHTLEAVEREQUESTMESSAGE_H