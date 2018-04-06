#ifndef GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H
#define GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/GameContextRemoveElementMessage.h"

class GameContextRemoveElementWithEventMessage : public GameContextRemoveElementMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextRemoveElementWithEventMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextRemoveElementWithEventMessage(Reader *param1);
  GameContextRemoveElementWithEventMessage();

  uint elementEventId;
};

#endif // GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE_H