#ifndef GUILDMODIFICATIONSTARTEDMESSAGE_H
#define GUILDMODIFICATIONSTARTEDMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class GuildModificationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildModificationStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildModificationStartedMessage(Reader *param1);
  GuildModificationStartedMessage();

  bool canChangeName;
  bool canChangeEmblem;
};

#endif // GUILDMODIFICATIONSTARTEDMESSAGE_H