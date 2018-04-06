#ifndef GUILDGETINFORMATIONSMESSAGE_H
#define GUILDGETINFORMATIONSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildGetInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildGetInformationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildGetInformationsMessage(Reader *param1);
  GuildGetInformationsMessage();

  uint infoType;
};

#endif // GUILDGETINFORMATIONSMESSAGE_H