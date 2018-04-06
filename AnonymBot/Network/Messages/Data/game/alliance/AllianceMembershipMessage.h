#ifndef ALLIANCEMEMBERSHIPMESSAGE_H
#define ALLIANCEMEMBERSHIPMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/alliance/AllianceJoinedMessage.h"
#include "Network/Classes/Data/game/context/roleplay/AllianceInformations.h"

class AllianceMembershipMessage : public AllianceJoinedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AllianceMembershipMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AllianceMembershipMessage(Reader *param1);
  AllianceMembershipMessage();
};

#endif // ALLIANCEMEMBERSHIPMESSAGE_H