#ifndef STATEDMAPUPDATEMESSAGE_H
#define STATEDMAPUPDATEMESSAGE_H

#include "Network/Classes/Data/game/interactive/StatedElement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/interactive/StatedElement.h"

class StatedMapUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatedMapUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatedMapUpdateMessage(Reader *param1);
  StatedMapUpdateMessage();

  QList<StatedElement> statedElements;
};

#endif // STATEDMAPUPDATEMESSAGE_H