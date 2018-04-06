#ifndef GUILDINFORMATIONS_H
#define GUILDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Classes/Data/game/context/roleplay/BasicGuildInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildInformations : public BasicGuildInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInformations(Reader *param1);
  GuildInformations();
  bool operator==(const GuildInformations &compared);

  GuildEmblem guildEmblem;
};

#endif // GUILDINFORMATIONS_H