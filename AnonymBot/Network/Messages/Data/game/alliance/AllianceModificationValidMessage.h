#ifndef ALLIANCEMODIFICATIONVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AllianceModificationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceModificationValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceModificationValidMessage(Reader *param1);
  AllianceModificationValidMessage();

  QString allianceName;
  QString allianceTag;
  GuildEmblem Alliancemblem;
};

#endif // ALLIANCEMODIFICATIONVALIDMESSAGE_H