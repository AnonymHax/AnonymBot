#ifndef PARTYFOLLOWMEMBERREQUESTMESSAGE_H
#define PARTYFOLLOWMEMBERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyFollowMemberRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyFollowMemberRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyFollowMemberRequestMessage(Reader *param1);
  PartyFollowMemberRequestMessage();

  double playerId;
};

#endif // PARTYFOLLOWMEMBERREQUESTMESSAGE_H