#ifndef PARTYLOCATEMEMBERSMESSAGE_H
#define PARTYLOCATEMEMBERSMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberGeoPosition.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/party/AbstractPartyMessage.h"
#include "Network/Classes/Data/game/context/roleplay/party/PartyMemberGeoPosition.h"

class PartyLocateMembersMessage : public AbstractPartyMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PartyLocateMembersMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PartyLocateMembersMessage(Reader *param1);
  PartyLocateMembersMessage();

  QList<PartyMemberGeoPosition> geopositions;
};

#endif // PARTYLOCATEMEMBERSMESSAGE_H