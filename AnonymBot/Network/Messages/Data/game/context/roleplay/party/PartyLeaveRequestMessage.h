#ifndef PARTYLEAVEREQUESTMESSAGE_H
#define PARTYLEAVEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLeaveRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLeaveRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLeaveRequestMessage(Reader *param1);
  PartyLeaveRequestMessage();
};

#endif // PARTYLEAVEREQUESTMESSAGE_H