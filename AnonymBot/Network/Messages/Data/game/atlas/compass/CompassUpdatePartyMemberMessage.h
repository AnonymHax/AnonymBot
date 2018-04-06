#ifndef COMPASSUPDATEPARTYMEMBERMESSAGE_H
#define COMPASSUPDATEPARTYMEMBERMESSAGE_H

#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/atlas/compass/CompassUpdateMessage.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"

class CompassUpdatePartyMemberMessage : public CompassUpdateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CompassUpdatePartyMemberMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CompassUpdatePartyMemberMessage(Reader *param1);
  CompassUpdatePartyMemberMessage();

  double memberId;
  bool active;
};

#endif // COMPASSUPDATEPARTYMEMBERMESSAGE_H