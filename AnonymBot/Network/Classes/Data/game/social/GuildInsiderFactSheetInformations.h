#ifndef GUILDINSIDERFACTSHEETINFORMATIONS_H
#define GUILDINSIDERFACTSHEETINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class GuildInsiderFactSheetInformations : public GuildFactSheetInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInsiderFactSheetInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInsiderFactSheetInformations(Reader *param1);
  GuildInsiderFactSheetInformations();
  bool operator==(const GuildInsiderFactSheetInformations &compared);

  QString leaderName;
  uint nbConnectedMembers;
  uint nbTaxCollectors;
  uint lastActivity;
};

#endif // GUILDINSIDERFACTSHEETINFORMATIONS_H