#ifndef PARTYMEMBERARENAINFORMATIONS_H
#define PARTYMEMBERARENAINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionMemberInformations.h"

class PartyMemberArenaInformations : public PartyMemberInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberArenaInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberArenaInformations(Reader *param1);
  PartyMemberArenaInformations();
  bool operator==(const PartyMemberArenaInformations &compared);

  uint rank;
};

#endif // PARTYMEMBERARENAINFORMATIONS_H