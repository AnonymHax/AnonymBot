#ifndef PARTYUPDATELIGHTMESSAGE_H
#define PARTYUPDATELIGHTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"

class PartyUpdateLightMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyUpdateLightMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyUpdateLightMessage(Reader *param1);
  PartyUpdateLightMessage();

  double id;
  uint lifePoints;
  uint maxLifePoints;
  uint prospecting;
  uint regenRate;
};

#endif // PARTYUPDATELIGHTMESSAGE_H