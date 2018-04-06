#ifndef GAMEMAPMOVEMENTCANCELMESSAGE_H
#define GAMEMAPMOVEMENTCANCELMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapMovementCancelMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapMovementCancelMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapMovementCancelMessage(Reader *param1);
  GameMapMovementCancelMessage();

  uint cellId;
};

#endif // GAMEMAPMOVEMENTCANCELMESSAGE_H