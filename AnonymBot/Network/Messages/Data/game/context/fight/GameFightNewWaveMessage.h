#ifndef GAMEFIGHTNEWWAVEMESSAGE_H
#define GAMEFIGHTNEWWAVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightNewWaveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightNewWaveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightNewWaveMessage(Reader *param1);
  GameFightNewWaveMessage();

  uint id;
  uint teamId;
  int nbTurnBeforeNextWave;
};

#endif // GAMEFIGHTNEWWAVEMESSAGE_H