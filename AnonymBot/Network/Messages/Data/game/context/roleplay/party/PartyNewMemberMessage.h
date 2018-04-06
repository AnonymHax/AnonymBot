#ifndef PARTYNEWMEMBERMESSAGE_H
#define PARTYNEWMEMBERMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/PartyUpdateMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberInformations.h"

class PartyNewMemberMessage : public PartyUpdateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyNewMemberMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyNewMemberMessage(Reader *param1);
  PartyNewMemberMessage();
};

#endif // PARTYNEWMEMBERMESSAGE_H