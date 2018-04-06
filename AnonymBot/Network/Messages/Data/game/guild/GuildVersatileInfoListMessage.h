#ifndef GUILDVERSATILEINFOLISTMESSAGE_H
#define GUILDVERSATILEINFOLISTMESSAGE_H

#include "Network/Classes/Data/game/social/GuildVersatileInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/GuildVersatileInformations.h"
#include "Network/Classes/ClassManager.h"

class GuildVersatileInfoListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildVersatileInfoListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildVersatileInfoListMessage(Reader *param1);
  GuildVersatileInfoListMessage();

  QList<QSharedPointer<GuildVersatileInformations>> guilds;
};

#endif // GUILDVERSATILEINFOLISTMESSAGE_H