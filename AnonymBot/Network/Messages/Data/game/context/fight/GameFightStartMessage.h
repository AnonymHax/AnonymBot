#ifndef GAMEFIGHTSTARTMESSAGE_H
#define GAMEFIGHTSTARTMESSAGE_H

#include "Network/Classes/Data/game/idol/Idol.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/idol/Idol.h"

class GameFightStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightStartMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightStartMessage(Reader *param1);
  GameFightStartMessage();

  QList<QSharedPointer<Idol>> idols;
};

#endif // GAMEFIGHTSTARTMESSAGE_H