#ifndef GAMEFIGHTNEWROUNDMESSAGE_H
#define GAMEFIGHTNEWROUNDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightNewRoundMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightNewRoundMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightNewRoundMessage(Reader *param1);
  GameFightNewRoundMessage();

  uint roundNumber;
};

#endif // GAMEFIGHTNEWROUNDMESSAGE_H