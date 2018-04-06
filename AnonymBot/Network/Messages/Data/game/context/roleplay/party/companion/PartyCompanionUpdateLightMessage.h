#ifndef PARTYCOMPANIONUPDATELIGHTMESSAGE_H
#define PARTYCOMPANIONUPDATELIGHTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyUpdateLightMessage.h"

class PartyCompanionUpdateLightMessage : public PartyUpdateLightMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyCompanionUpdateLightMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyCompanionUpdateLightMessage(Reader *param1);
  PartyCompanionUpdateLightMessage();

  uint indexId;
};

#endif // PARTYCOMPANIONUPDATELIGHTMESSAGE_H