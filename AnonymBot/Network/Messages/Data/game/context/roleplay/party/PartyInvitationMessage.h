#ifndef PARTYINVITATIONMESSAGE_H
#define PARTYINVITATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyInvitationMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyInvitationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyInvitationMessage(Reader *param1);
  PartyInvitationMessage();

  uint partyType;
  QString partyName;
  uint maxParticipants;
  double fromId;
  QString fromName;
  double toId;
};

#endif // PARTYINVITATIONMESSAGE_H