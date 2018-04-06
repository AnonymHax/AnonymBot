#ifndef GUILDSPELLUPGRADEREQUESTMESSAGE_H
#define GUILDSPELLUPGRADEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildSpellUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildSpellUpgradeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildSpellUpgradeRequestMessage(Reader *param1);
  GuildSpellUpgradeRequestMessage();

  uint spellId;
};

#endif // GUILDSPELLUPGRADEREQUESTMESSAGE_H