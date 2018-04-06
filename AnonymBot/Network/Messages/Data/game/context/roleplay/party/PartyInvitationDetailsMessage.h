#ifndef PARTYINVITATIONDETAILSMESSAGE_H
#define PARTYINVITATIONDETAILSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyInvitationMemberInformations.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyGuestInformations.h"

class PartyInvitationDetailsMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationDetailsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationDetailsMessage(Reader *param1);
  PartyInvitationDetailsMessage();

  uint partyType;
  QString partyName;
  double fromId;
  QString fromName;
  double leaderId;
  QList<QSharedPointer<PartyInvitationMemberInformations>> members;
  QList<QSharedPointer<PartyGuestInformations>> guests;
};

#endif // PARTYINVITATIONDETAILSMESSAGE_H