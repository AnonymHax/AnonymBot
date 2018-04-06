#ifndef GUILDPADDOCKBOUGHTMESSAGE_H
#define GUILDPADDOCKBOUGHTMESSAGE_H

#include "Network/Classes/Data/game/paddock/PaddockContentInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/paddock/PaddockContentInformations.h"

class GuildPaddockBoughtMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildPaddockBoughtMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildPaddockBoughtMessage(Reader *param1);
  GuildPaddockBoughtMessage();

  QSharedPointer<PaddockContentInformations> paddockInfo;
};

#endif // GUILDPADDOCKBOUGHTMESSAGE_H