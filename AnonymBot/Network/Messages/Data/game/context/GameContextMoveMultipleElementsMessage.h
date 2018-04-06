#ifndef GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H
#define GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H

#include "Network/Classes/Data/game/context/EntityMovementInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/EntityMovementInformations.h"

class GameContextMoveMultipleElementsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextMoveMultipleElementsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextMoveMultipleElementsMessage(Reader *param1);
  GameContextMoveMultipleElementsMessage();

  QList<EntityMovementInformations> movements;
};

#endif // GAMECONTEXTMOVEMULTIPLEELEMENTSMESSAGE_H