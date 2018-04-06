#ifndef PLAYERSTATUSUPDATEREQUESTMESSAGE_H
#define PLAYERSTATUSUPDATEREQUESTMESSAGE_H

#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/status/PlayerStatus.h"
#include "Network/Classes/ClassManager.h"

class PlayerStatusUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PlayerStatusUpdateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PlayerStatusUpdateRequestMessage(Reader *param1);
  PlayerStatusUpdateRequestMessage();

  QSharedPointer<PlayerStatus> status;
};

#endif // PLAYERSTATUSUPDATEREQUESTMESSAGE_H