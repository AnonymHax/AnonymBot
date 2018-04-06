#ifndef PARTYRESTRICTEDMESSAGE_H
#define PARTYRESTRICTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyRestrictedMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyRestrictedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyRestrictedMessage(Reader *param1);
  PartyRestrictedMessage();

  bool restricted;
};

#endif // PARTYRESTRICTEDMESSAGE_H