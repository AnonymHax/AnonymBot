#ifndef GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H
#define GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFightPlayersHelpersLeaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFightPlayersHelpersLeaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFightPlayersHelpersLeaveMessage(Reader *param1);
  GuildFightPlayersHelpersLeaveMessage();

  uint fightId;
  double playerId;
};

#endif // GUILDFIGHTPLAYERSHELPERSLEAVEMESSAGE_H