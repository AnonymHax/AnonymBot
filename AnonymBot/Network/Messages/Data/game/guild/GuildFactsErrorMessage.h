#ifndef GUILDFACTSERRORMESSAGE_H
#define GUILDFACTSERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuildFactsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFactsErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFactsErrorMessage(Reader *param1);
  GuildFactsErrorMessage();

  uint guildId;
};

#endif // GUILDFACTSERRORMESSAGE_H