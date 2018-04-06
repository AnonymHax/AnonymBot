#ifndef GAMECONTEXTKICKMESSAGE_H
#define GAMECONTEXTKICKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameContextKickMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextKickMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextKickMessage(Reader *param1);
  GameContextKickMessage();

  double targetId;
};

#endif // GAMECONTEXTKICKMESSAGE_H