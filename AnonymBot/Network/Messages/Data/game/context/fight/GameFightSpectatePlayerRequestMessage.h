#ifndef GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H
#define GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightSpectatePlayerRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightSpectatePlayerRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightSpectatePlayerRequestMessage(Reader *param1);
  GameFightSpectatePlayerRequestMessage();

  double playerId;
};

#endif // GAMEFIGHTSPECTATEPLAYERREQUESTMESSAGE_H