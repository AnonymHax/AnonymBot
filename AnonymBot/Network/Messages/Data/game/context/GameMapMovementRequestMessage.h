#ifndef GAMEMAPMOVEMENTREQUESTMESSAGE_H
#define GAMEMAPMOVEMENTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapMovementRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapMovementRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapMovementRequestMessage(Reader *param1);
  GameMapMovementRequestMessage();

  QList<uint> keyMovements;
  uint mapId;
};

#endif // GAMEMAPMOVEMENTREQUESTMESSAGE_H