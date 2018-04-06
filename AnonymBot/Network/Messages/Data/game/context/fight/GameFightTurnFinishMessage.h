#ifndef GAMEFIGHTTURNFINISHMESSAGE_H
#define GAMEFIGHTTURNFINISHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameFightTurnFinishMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameFightTurnFinishMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameFightTurnFinishMessage(Reader *param1);
  GameFightTurnFinishMessage();

  bool isAfk;
};

#endif // GAMEFIGHTTURNFINISHMESSAGE_H