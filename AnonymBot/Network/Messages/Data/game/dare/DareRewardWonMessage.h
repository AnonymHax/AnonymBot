#ifndef DAREREWARDWONMESSAGE_H
#define DAREREWARDWONMESSAGE_H

#include "Network/Classes/Data/game/dare/DareReward.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/dare/DareReward.h"

class DareRewardWonMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareRewardWonMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareRewardWonMessage(Reader *param1);
  DareRewardWonMessage();

  DareReward reward;
};

#endif // DAREREWARDWONMESSAGE_H