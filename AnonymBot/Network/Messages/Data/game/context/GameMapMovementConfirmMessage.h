#ifndef GAMEMAPMOVEMENTCONFIRMMESSAGE_H
#define GAMEMAPMOVEMENTCONFIRMMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapMovementConfirmMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapMovementConfirmMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapMovementConfirmMessage(Reader *param1);
  GameMapMovementConfirmMessage();
};

#endif // GAMEMAPMOVEMENTCONFIRMMESSAGE_H