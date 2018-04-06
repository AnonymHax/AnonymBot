#ifndef COMPASSUPDATEMESSAGE_H
#define COMPASSUPDATEMESSAGE_H

#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/MapCoordinates.h"
#include "Network/Classes/ClassManager.h"

class CompassUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CompassUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CompassUpdateMessage(Reader *param1);
  CompassUpdateMessage();

  uint type;
  QSharedPointer<MapCoordinates> coords;
};

#endif // COMPASSUPDATEMESSAGE_H