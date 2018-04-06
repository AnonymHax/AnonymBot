#ifndef STATSUPGRADERESULTMESSAGE_H
#define STATSUPGRADERESULTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StatsUpgradeResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatsUpgradeResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatsUpgradeResultMessage(Reader *param1);
  StatsUpgradeResultMessage();

  int result;
  uint nbCharacBoost;
};

#endif // STATSUPGRADERESULTMESSAGE_H