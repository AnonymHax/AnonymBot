#ifndef GAMECONTEXTMOVEELEMENTMESSAGE_H
#define GAMECONTEXTMOVEELEMENTMESSAGE_H

#include "Network/Classes/Data/game/context/EntityMovementInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/EntityMovementInformations.h"

class GameContextMoveElementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextMoveElementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextMoveElementMessage(Reader *param1);
  GameContextMoveElementMessage();

  EntityMovementInformations movement;
};

#endif // GAMECONTEXTMOVEELEMENTMESSAGE_H