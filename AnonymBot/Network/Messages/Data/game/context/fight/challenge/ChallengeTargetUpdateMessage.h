#ifndef CHALLENGETARGETUPDATEMESSAGE_H
#define CHALLENGETARGETUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeTargetUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeTargetUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeTargetUpdateMessage(Reader *param1);
  ChallengeTargetUpdateMessage();

  uint challengeId;
  double targetId;
};

#endif // CHALLENGETARGETUPDATEMESSAGE_H