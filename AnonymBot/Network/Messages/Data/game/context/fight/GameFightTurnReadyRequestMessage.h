#ifndef GAMEFIGHTTURNREADYREQUESTMESSAGE_H
#define GAMEFIGHTTURNREADYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnReadyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnReadyRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnReadyRequestMessage(Reader *param1);
  GameFightTurnReadyRequestMessage();

  double id;
};

#endif // GAMEFIGHTTURNREADYREQUESTMESSAGE_H