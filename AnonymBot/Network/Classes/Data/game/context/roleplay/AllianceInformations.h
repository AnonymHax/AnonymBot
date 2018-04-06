#ifndef ALLIANCEINFORMATIONS_H
#define ALLIANCEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"
#include "Network/Classes/Data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "Network/Classes/Data/game/guild/GuildEmblem.h"

class AllianceInformations : public BasicNamedAllianceInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceInformations(Reader *param1);
  AllianceInformations();
  bool operator==(const AllianceInformations &compared);

  GuildEmblem allianceEmblem;
};

#endif // ALLIANCEINFORMATIONS_H