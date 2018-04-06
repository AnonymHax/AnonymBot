#ifndef GUILDCHARACSUPGRADEREQUESTMESSAGE_H
#define GUILDCHARACSUPGRADEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildCharacsUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildCharacsUpgradeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildCharacsUpgradeRequestMessage(Reader *param1);
  GuildCharacsUpgradeRequestMessage();

  uint charaTypeTarget;
};

#endif // GUILDCHARACSUPGRADEREQUESTMESSAGE_H