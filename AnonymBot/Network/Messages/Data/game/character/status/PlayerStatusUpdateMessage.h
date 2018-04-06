#ifndef PLAYERSTATUSUPDATEMESSAGE_H
#define PLAYERSTATUSUPDATEMESSAGE_H

#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/ClassManager.h"

class PlayerStatusUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PlayerStatusUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PlayerStatusUpdateMessage(Reader *param1);
  PlayerStatusUpdateMessage();

  uint accountId;
  double playerId;
  QSharedPointer<PlayerStatus> status;
};

#endif // PLAYERSTATUSUPDATEMESSAGE_H