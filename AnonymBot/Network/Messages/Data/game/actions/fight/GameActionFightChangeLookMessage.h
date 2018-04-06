#ifndef GAMEACTIONFIGHTCHANGELOOKMESSAGE_H
#define GAMEACTIONFIGHTCHANGELOOKMESSAGE_H

#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class GameActionFightChangeLookMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameActionFightChangeLookMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameActionFightChangeLookMessage(Reader *param1);
  GameActionFightChangeLookMessage();

  double targetId;
  QSharedPointer<EntityLook> entityLook;
};

#endif // GAMEACTIONFIGHTCHANGELOOKMESSAGE_H