#ifndef GAMEMAPNOMOVEMENTMESSAGE_H
#define GAMEMAPNOMOVEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapNoMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapNoMovementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapNoMovementMessage(Reader *param1);
  GameMapNoMovementMessage();

  int cellX;
  int cellY;
};

#endif // GAMEMAPNOMOVEMENTMESSAGE_H