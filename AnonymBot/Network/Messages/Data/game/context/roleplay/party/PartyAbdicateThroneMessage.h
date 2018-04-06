#ifndef PARTYABDICATETHRONEMESSAGE_H
#define PARTYABDICATETHRONEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyAbdicateThroneMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyAbdicateThroneMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyAbdicateThroneMessage(Reader *param1);
  PartyAbdicateThroneMessage();

  double playerId;
};

#endif // PARTYABDICATETHRONEMESSAGE_H