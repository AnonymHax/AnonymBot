#ifndef CHALLENGETARGETSLISTMESSAGE_H
#define CHALLENGETARGETSLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ChallengeTargetsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ChallengeTargetsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ChallengeTargetsListMessage(Reader *param1);
  ChallengeTargetsListMessage();

  QList<double> targetIds;
  QList<int> targetCells;
};

#endif // CHALLENGETARGETSLISTMESSAGE_H