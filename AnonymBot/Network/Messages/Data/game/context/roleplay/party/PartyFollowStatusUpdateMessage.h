#ifndef PARTYFOLLOWSTATUSUPDATEMESSAGE_H
#define PARTYFOLLOWSTATUSUPDATEMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class PartyFollowStatusUpdateMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyFollowStatusUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyFollowStatusUpdateMessage(Reader *param1);
  PartyFollowStatusUpdateMessage();

  bool success;
  bool isFollowed;
  double followedId;
};

#endif // PARTYFOLLOWSTATUSUPDATEMESSAGE_H