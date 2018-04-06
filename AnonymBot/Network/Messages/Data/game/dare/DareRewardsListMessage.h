#ifndef DAREREWARDSLISTMESSAGE_H
#define DAREREWARDSLISTMESSAGE_H

#include "Network/Classes/Data/game/dare/DareReward.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareReward.h"

class DareRewardsListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareRewardsListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareRewardsListMessage(Reader *param1);
  DareRewardsListMessage();

  QList<DareReward> rewards;
};

#endif // DAREREWARDSLISTMESSAGE_H