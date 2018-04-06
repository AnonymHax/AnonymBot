#ifndef JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H
#define JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/context/roleplay/job/JobAllowMultiCraftRequestMessage.h"

class JobMultiCraftAvailableSkillsMessage : public JobAllowMultiCraftRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_JobMultiCraftAvailableSkillsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_JobMultiCraftAvailableSkillsMessage(Reader *param1);
  JobMultiCraftAvailableSkillsMessage();

  double playerId;
  QList<uint> skills;
};

#endif // JOBMULTICRAFTAVAILABLESKILLSMESSAGE_H