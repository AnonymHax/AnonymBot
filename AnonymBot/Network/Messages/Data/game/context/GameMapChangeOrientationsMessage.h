#ifndef GAMEMAPCHANGEORIENTATIONSMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONSMESSAGE_H

#include "Network/Classes/Data/game/context/ActorOrientation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/ActorOrientation.h"

class GameMapChangeOrientationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapChangeOrientationsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapChangeOrientationsMessage(Reader *param1);
  GameMapChangeOrientationsMessage();

  QList<ActorOrientation> orientations;
};

#endif // GAMEMAPCHANGEORIENTATIONSMESSAGE_H