#ifndef PARTYLOCATEMEMBERSREQUESTMESSAGE_H
#define PARTYLOCATEMEMBERSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLocateMembersRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLocateMembersRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLocateMembersRequestMessage(Reader *param1);
  PartyLocateMembersRequestMessage();
};

#endif // PARTYLOCATEMEMBERSREQUESTMESSAGE_H