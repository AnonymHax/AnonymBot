#ifndef PARTYKICKREQUESTMESSAGE_H
#define PARTYKICKREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"

class PartyKickRequestMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyKickRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyKickRequestMessage(Reader *param1);
  PartyKickRequestMessage();

  double playerId;
};

#endif // PARTYKICKREQUESTMESSAGE_H