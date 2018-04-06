#ifndef ALLIANCEINSIDERINFOMESSAGE_H
#define ALLIANCEINSIDERINFOMESSAGE_H

#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Classes/Data/game/social/GuildInsiderFactSheetInformations.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/AllianceFactSheetInformations.h"
#include "Network/Classes/Data/game/social/GuildInsiderFactSheetInformations.h"
#include "Network/Classes/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "Network/Classes/ClassManager.h"

class AllianceInsiderInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInsiderInfoMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInsiderInfoMessage(Reader *param1);
  AllianceInsiderInfoMessage();

  QSharedPointer<AllianceFactSheetInformations> allianceInfos;
  QList<QSharedPointer<GuildInsiderFactSheetInformations>> guilds;
  QList<QSharedPointer<PrismSubareaEmptyInfo>> prisms;
};

#endif // ALLIANCEINSIDERINFOMESSAGE_H