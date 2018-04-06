#ifndef PARTYUPDATEMESSAGE_H
#define PARTYUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyEventMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Classes/ClassManager.h"

class PartyUpdateMessage : public AbstractPartyEventMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyUpdateMessage(Reader *param1);
  PartyUpdateMessage();

  QSharedPointer<PartyMemberInformations> memberInformations;
};

#endif // PARTYUPDATEMESSAGE_H