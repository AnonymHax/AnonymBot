#ifndef PARTYLEADERUPDATEMESSAGE_H
#define PARTYLEADERUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyLeaderUpdateMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLeaderUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLeaderUpdateMessage(Reader *param1);
  PartyLeaderUpdateMessage();

  double partyLeaderId;
};

#endif // PARTYLEADERUPDATEMESSAGE_H