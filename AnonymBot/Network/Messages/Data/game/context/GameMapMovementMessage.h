#ifndef GAMEMAPMOVEMENTMESSAGE_H
#define GAMEMAPMOVEMENTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapMovementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapMovementMessage(Reader *param1);
  GameMapMovementMessage();

  QList<uint> keyMovements;
  double actorId;
};

#endif // GAMEMAPMOVEMENTMESSAGE_H