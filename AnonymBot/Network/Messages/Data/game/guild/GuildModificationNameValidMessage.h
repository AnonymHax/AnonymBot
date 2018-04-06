#ifndef GUILDMODIFICATIONNAMEVALIDMESSAGE_H
#define GUILDMODIFICATIONNAMEVALIDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildModificationNameValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildModificationNameValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildModificationNameValidMessage(Reader *param1);
  GuildModificationNameValidMessage();

  QString guildName;
};

#endif // GUILDMODIFICATIONNAMEVALIDMESSAGE_H