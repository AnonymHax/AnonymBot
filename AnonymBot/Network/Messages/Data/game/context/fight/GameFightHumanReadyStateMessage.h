#ifndef GAMEFIGHTHUMANREADYSTATEMESSAGE_H
#define GAMEFIGHTHUMANREADYSTATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightHumanReadyStateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightHumanReadyStateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightHumanReadyStateMessage(Reader *param1);
  GameFightHumanReadyStateMessage();

  double characterId;
  bool isReady;
};

#endif // GAMEFIGHTHUMANREADYSTATEMESSAGE_H