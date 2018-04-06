#ifndef GAMEMAPCHANGEORIENTATIONMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONMESSAGE_H

#include "Network/Classes/Data/game/context/ActorOrientation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/ActorOrientation.h"

class GameMapChangeOrientationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapChangeOrientationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapChangeOrientationMessage(Reader *param1);
  GameMapChangeOrientationMessage();

  ActorOrientation orientation;
};

#endif // GAMEMAPCHANGEORIENTATIONMESSAGE_H