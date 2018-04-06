#ifndef GUILDFIGHTJOINREQUESTMESSAGE_H
#define GUILDFIGHTJOINREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFightJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightJoinRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightJoinRequestMessage(Reader *param1);
  GuildFightJoinRequestMessage();

  int taxCollectorId;
};

#endif // GUILDFIGHTJOINREQUESTMESSAGE_H