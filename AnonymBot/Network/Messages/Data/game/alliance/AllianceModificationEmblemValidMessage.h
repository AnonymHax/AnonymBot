#ifndef ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H
#define ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AllianceModificationEmblemValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceModificationEmblemValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceModificationEmblemValidMessage(Reader *param1);
  AllianceModificationEmblemValidMessage();

  GuildEmblem Alliancemblem;
};

#endif // ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE_H