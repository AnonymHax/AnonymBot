#ifndef HUMANOPTIONGUILD_H
#define HUMANOPTIONGUILD_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionGuild : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionGuild(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionGuild(Reader *param1);
  HumanOptionGuild();
  bool operator==(const HumanOptionGuild &compared);

  QSharedPointer<GuildInformations> guildInformations;
};

#endif // HUMANOPTIONGUILD_H