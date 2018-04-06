#ifndef ALLIANCEDGUILDFACTSHEETINFORMATIONS_H
#define ALLIANCEDGUILDFACTSHEETINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInformations.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AlliancedGuildFactSheetInformations : public GuildInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AlliancedGuildFactSheetInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AlliancedGuildFactSheetInformations(Reader *param1);
  AlliancedGuildFactSheetInformations();
  bool operator==(const AlliancedGuildFactSheetInformations &compared);

  QSharedPointer<BasicNamedAllianceInformations> allianceInfos;
};

#endif // ALLIANCEDGUILDFACTSHEETINFORMATIONS_H