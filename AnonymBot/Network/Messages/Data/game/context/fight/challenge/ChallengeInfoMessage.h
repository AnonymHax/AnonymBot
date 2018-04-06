#ifndef CHALLENGEINFOMESSAGE_H
#define CHALLENGEINFOMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeInfoMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeInfoMessage(Reader *param1);
  ChallengeInfoMessage();

  uint challengeId;
  double targetId;
  uint xpBonus;
  uint dropBonus;
};

#endif // CHALLENGEINFOMESSAGE_H