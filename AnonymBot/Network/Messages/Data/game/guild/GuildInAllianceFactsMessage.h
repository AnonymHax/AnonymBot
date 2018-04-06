#ifndef GUILDINALLIANCEFACTSMESSAGE_H
#define GUILDINALLIANCEFACTSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/guild/GuildFactsMessage.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"

class GuildInAllianceFactsMessage : public GuildFactsMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildInAllianceFactsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildInAllianceFactsMessage(Reader *param1);
  GuildInAllianceFactsMessage();

  QSharedPointer<BasicNamedAllianceInformations> allianceInfos;
};

#endif // GUILDINALLIANCEFACTSMESSAGE_H