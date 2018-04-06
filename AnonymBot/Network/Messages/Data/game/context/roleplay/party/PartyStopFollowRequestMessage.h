#ifndef PARTYSTOPFOLLOWREQUESTMESSAGE_H
#define PARTYSTOPFOLLOWREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyStopFollowRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyStopFollowRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyStopFollowRequestMessage(Reader *param1);
  PartyStopFollowRequestMessage();

  double playerId;
};

#endif // PARTYSTOPFOLLOWREQUESTMESSAGE_H