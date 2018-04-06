#ifndef PARTYJOINMESSAGE_H
#define PARTYJOINMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "Network/Classes/ClassManager.h"

class PartyJoinMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyJoinMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyJoinMessage(Reader *param1);
  PartyJoinMessage();

  uint partyType;
  double partyLeaderId;
  uint maxParticipants;
  QList<QSharedPointer<PartyMemberInformations>> members;
  QList<QSharedPointer<PartyGuestInformations>> guests;
  bool restricted;
  QString partyName;
};

#endif // PARTYJOINMESSAGE_H