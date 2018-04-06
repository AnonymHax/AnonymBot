#ifndef PARTYMEMBERINFORMATIONS_H
#define PARTYMEMBERINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionMemberInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionMemberInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/character/choice/CharacterBaseInformations.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionMemberInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/ClassManager.h"

class PartyMemberInformations : public CharacterBaseInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberInformations(Reader *param1);
  PartyMemberInformations();
  bool operator==(const PartyMemberInformations &compared);

  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;
  uint initiative;
  int alignmentSide;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QSharedPointer<PlayerStatus> status;
  QList<QSharedPointer<PartyCompanionMemberInformations>> companions;
};

#endif // PARTYMEMBERINFORMATIONS_H