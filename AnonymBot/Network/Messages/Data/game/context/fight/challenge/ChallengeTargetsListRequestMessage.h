#ifndef CHALLENGETARGETSLISTREQUESTMESSAGE_H
#define CHALLENGETARGETSLISTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeTargetsListRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeTargetsListRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeTargetsListRequestMessage(Reader *param1);
  ChallengeTargetsListRequestMessage();

  uint challengeId;
};

#endif // CHALLENGETARGETSLISTREQUESTMESSAGE_H