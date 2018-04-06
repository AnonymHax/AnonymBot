#ifndef GUILDFACTSHEETINFORMATIONS_H
#define GUILDFACTSHEETINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildFactSheetInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFactSheetInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFactSheetInformations(Reader *param1);
  GuildFactSheetInformations();
  bool operator==(const GuildFactSheetInformations &compared);

  double leaderId;
  uint nbMembers;
};

#endif // GUILDFACTSHEETINFORMATIONS_H