#ifndef COMPASSUPDATEPVPSEEKMESSAGE_H
#define COMPASSUPDATEPVPSEEKMESSAGE_H

#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/atlas/compass/CompassUpdateMessage.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"

class CompassUpdatePvpSeekMessage : public CompassUpdateMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CompassUpdatePvpSeekMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CompassUpdatePvpSeekMessage(Reader *param1);
  CompassUpdatePvpSeekMessage();

  double memberId;
  QString memberName;
};

#endif // COMPASSUPDATEPVPSEEKMESSAGE_H