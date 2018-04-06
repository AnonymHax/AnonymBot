#ifndef PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H
#define PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyFollowMemberRequestMessage.h"

class PartyFollowThisMemberRequestMessage : public PartyFollowMemberRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyFollowThisMemberRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyFollowThisMemberRequestMessage(Reader *param1);
  PartyFollowThisMemberRequestMessage();

  bool enabled;
};

#endif // PARTYFOLLOWTHISMEMBERREQUESTMESSAGE_H