#ifndef HOUSEINFORMATIONSEXTENDED_H
#define HOUSEINFORMATIONSEXTENDED_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/house/HouseInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"

class HouseInformationsExtended : public HouseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HouseInformationsExtended(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HouseInformationsExtended(Reader *param1);
  HouseInformationsExtended();
  bool operator==(const HouseInformationsExtended &compared);

  QSharedPointer<GuildInformations> guildInfo;
};

#endif // HOUSEINFORMATIONSEXTENDED_H