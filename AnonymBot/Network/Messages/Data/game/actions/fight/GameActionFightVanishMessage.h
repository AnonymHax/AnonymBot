#ifndef GAMEACTIONFIGHTVANISHMESSAGE_H
#define GAMEACTIONFIGHTVANISHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class GameActionFightVanishMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightVanishMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightVanishMessage(Reader *param1);
  GameActionFightVanishMessage();

  double targetId;
};

#endif // GAMEACTIONFIGHTVANISHMESSAGE_H