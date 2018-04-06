#ifndef ALLIANCECHANGEGUILDRIGHTSMESSAGE_H
#define ALLIANCECHANGEGUILDRIGHTSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AllianceChangeGuildRightsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceChangeGuildRightsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceChangeGuildRightsMessage(Reader *param1);
  AllianceChangeGuildRightsMessage();

  uint guildId;
  uint rights;
};

#endif // ALLIANCECHANGEGUILDRIGHTSMESSAGE_H