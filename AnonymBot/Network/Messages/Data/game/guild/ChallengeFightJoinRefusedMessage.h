#ifndef CHALLENGEFIGHTJOINREFUSEDMESSAGE_H
#define CHALLENGEFIGHTJOINREFUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeFightJoinRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeFightJoinRefusedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeFightJoinRefusedMessage(Reader *param1);
  ChallengeFightJoinRefusedMessage();

  double playerId;
  int reason;
};

#endif // CHALLENGEFIGHTJOINREFUSEDMESSAGE_H