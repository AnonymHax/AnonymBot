#ifndef ALLIANCECREATIONVALIDMESSAGE_H
#define ALLIANCECREATIONVALIDMESSAGE_H

#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AllianceCreationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceCreationValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceCreationValidMessage(Reader *param1);
  AllianceCreationValidMessage();

  QString allianceName;
  QString allianceTag;
  GuildEmblem allianceEmblem;
};

#endif // ALLIANCECREATIONVALIDMESSAGE_H