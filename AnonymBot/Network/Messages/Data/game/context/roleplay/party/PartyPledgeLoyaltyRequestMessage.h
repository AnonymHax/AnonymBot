#ifndef PARTYPLEDGELOYALTYREQUESTMESSAGE_H
#define PARTYPLEDGELOYALTYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyPledgeLoyaltyRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyPledgeLoyaltyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyPledgeLoyaltyRequestMessage(Reader *param1);
  PartyPledgeLoyaltyRequestMessage();

  bool loyal;
};

#endif // PARTYPLEDGELOYALTYREQUESTMESSAGE_H