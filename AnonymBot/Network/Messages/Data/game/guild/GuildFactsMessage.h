#ifndef GUILDFACTSMESSAGE_H
#define GUILDFACTSMESSAGE_H

#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/social/GuildFactSheetInformations.h"
#include "Network/Classes/Data/game/character/CharacterMinimalInformations.h"
#include "Network/Classes/ClassManager.h"

class GuildFactsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuildFactsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuildFactsMessage(Reader *param1);
  GuildFactsMessage();

  QSharedPointer<GuildFactSheetInformations> infos;
  uint creationDate;
  uint nbTaxCollectors;
  QList<CharacterMinimalInformations> members;
};

#endif // GUILDFACTSMESSAGE_H