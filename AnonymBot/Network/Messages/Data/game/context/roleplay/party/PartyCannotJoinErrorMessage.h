#ifndef PARTYCANNOTJOINERRORMESSAGE_H
#define PARTYCANNOTJOINERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyCannotJoinErrorMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCannotJoinErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCannotJoinErrorMessage(Reader *param1);
  PartyCannotJoinErrorMessage();

  uint reason;
};

#endif // PARTYCANNOTJOINERRORMESSAGE_H