#ifndef ALLIANCEFACTSMESSAGE_H
#define ALLIANCEFACTSMESSAGE_H

#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInAllianceInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Classes/Data/game/context/roleplay/GuildInAllianceInformations.h"
#include "Network/Classes/ClassManager.h"

class AllianceFactsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceFactsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceFactsMessage(Reader *param1);
  AllianceFactsMessage();

  QSharedPointer<AllianceFactSheetInformations> infos;
  QList<QSharedPointer<GuildInAllianceInformations>> guilds;
  QList<uint> controlledSubareaIds;
  double leaderCharacterId;
  QString leaderCharacterName;
};

#endif // ALLIANCEFACTSMESSAGE_H