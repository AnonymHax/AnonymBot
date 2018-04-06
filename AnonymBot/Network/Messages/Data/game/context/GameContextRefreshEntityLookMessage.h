#ifndef GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H
#define GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H

#include "Network/Classes/Data/game/look/EntityLook.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

class GameContextRefreshEntityLookMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameContextRefreshEntityLookMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameContextRefreshEntityLookMessage(Reader *param1);
  GameContextRefreshEntityLookMessage();

  double id;
  QSharedPointer<EntityLook> look;
};

#endif // GAMECONTEXTREFRESHENTITYLOOKMESSAGE_H