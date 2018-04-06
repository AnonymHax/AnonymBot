#ifndef PLAYERSTATUSEXTENDED_H
#define PLAYERSTATUSEXTENDED_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"

class PlayerStatusExtended : public PlayerStatus
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PlayerStatusExtended(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PlayerStatusExtended(Reader *param1);
  PlayerStatusExtended();
  bool operator==(const PlayerStatusExtended &compared);

  QString message;
};

#endif // PLAYERSTATUSEXTENDED_H