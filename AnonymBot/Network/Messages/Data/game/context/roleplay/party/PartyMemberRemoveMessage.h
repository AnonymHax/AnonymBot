#ifndef PARTYMEMBERREMOVEMESSAGE_H
#define PARTYMEMBERREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyMemberRemoveMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyMemberRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyMemberRemoveMessage(Reader *param1);
  PartyMemberRemoveMessage();

  double leavingPlayerId;
};

#endif // PARTYMEMBERREMOVEMESSAGE_H