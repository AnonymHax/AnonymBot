#ifndef GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H
#define GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameMapChangeOrientationRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameMapChangeOrientationRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameMapChangeOrientationRequestMessage(Reader *param1);
  GameMapChangeOrientationRequestMessage();

  uint direction;
};

#endif // GAMEMAPCHANGEORIENTATIONREQUESTMESSAGE_H