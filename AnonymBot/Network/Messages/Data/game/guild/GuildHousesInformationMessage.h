#ifndef GUILDHOUSESINFORMATIONMESSAGE_H
#define GUILDHOUSESINFORMATIONMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformationsForGuild.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/HouseInformationsForGuild.h"

class GuildHousesInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildHousesInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildHousesInformationMessage(Reader *param1);
  GuildHousesInformationMessage();

  QList<HouseInformationsForGuild> housesInformations;
};

#endif // GUILDHOUSESINFORMATIONMESSAGE_H