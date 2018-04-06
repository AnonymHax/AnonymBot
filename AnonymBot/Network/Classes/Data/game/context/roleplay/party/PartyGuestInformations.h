#ifndef PARTYGUESTINFORMATIONS_H
#define PARTYGUESTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/context/roleplay/party/companion/PartyCompanionBaseInformations.h"
#include "Network/Classes/ClassManager.h"

class PartyGuestInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyGuestInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyGuestInformations(Reader *param1);
  PartyGuestInformations();
  bool operator==(const PartyGuestInformations &compared);

  double guestId;
  double hostId;
  QString name;
  QSharedPointer<EntityLook> guestLook;
  int breed;
  bool sex;
  QSharedPointer<PlayerStatus> status;
  QList<QSharedPointer<PartyCompanionBaseInformations>> companions;
};

#endif // PARTYGUESTINFORMATIONS_H