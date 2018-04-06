#ifndef GUILDHOUSEUPDATEINFORMATIONMESSAGE_H
#define GUILDHOUSEUPDATEINFORMATIONMESSAGE_H

#include "Network/Classes/Data/game/house/HouseInformationsForGuild.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/house/HouseInformationsForGuild.h"

class GuildHouseUpdateInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildHouseUpdateInformationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildHouseUpdateInformationMessage(Reader *param1);
  GuildHouseUpdateInformationMessage();

  HouseInformationsForGuild housesInformations;
};

#endif // GUILDHOUSEUPDATEINFORMATIONMESSAGE_H