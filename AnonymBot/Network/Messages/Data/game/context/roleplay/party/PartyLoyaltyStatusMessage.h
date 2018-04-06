#ifndef PARTYLOYALTYSTATUSMESSAGE_H
#define PARTYLOYALTYSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyLoyaltyStatusMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLoyaltyStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLoyaltyStatusMessage(Reader *param1);
  PartyLoyaltyStatusMessage();

  bool loyal;
};

#endif // PARTYLOYALTYSTATUSMESSAGE_H