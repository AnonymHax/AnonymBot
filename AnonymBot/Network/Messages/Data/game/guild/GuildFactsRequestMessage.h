#ifndef GUILDFACTSREQUESTMESSAGE_H
#define GUILDFACTSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFactsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFactsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFactsRequestMessage(Reader *param1);
  GuildFactsRequestMessage();

  uint guildId;
};

#endif // GUILDFACTSREQUESTMESSAGE_H