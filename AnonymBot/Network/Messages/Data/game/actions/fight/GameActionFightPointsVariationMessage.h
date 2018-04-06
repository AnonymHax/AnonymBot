#ifndef GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H
#define GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightPointsVariationMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightPointsVariationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightPointsVariationMessage(Reader *param1);
  GameActionFightPointsVariationMessage();

  double targetId;
  int delta;
};

#endif // GAMEACTIONFIGHTPOINTSVARIATIONMESSAGE_H