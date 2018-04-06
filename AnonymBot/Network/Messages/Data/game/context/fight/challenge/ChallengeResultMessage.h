#ifndef CHALLENGERESULTMESSAGE_H
#define CHALLENGERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeResultMessage(Reader *param1);
  ChallengeResultMessage();

  uint challengeId;
  bool success;
};

#endif // CHALLENGERESULTMESSAGE_H