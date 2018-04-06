#ifndef PARTYMODIFIABLESTATUSMESSAGE_H
#define PARTYMODIFIABLESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyModifiableStatusMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyModifiableStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyModifiableStatusMessage(Reader *param1);
  PartyModifiableStatusMessage();

  bool enabled;
};

#endif // PARTYMODIFIABLESTATUSMESSAGE_H