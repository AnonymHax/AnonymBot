#ifndef STATSUPGRADEREQUESTMESSAGE_H
#define STATSUPGRADEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class StatsUpgradeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_StatsUpgradeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_StatsUpgradeRequestMessage(Reader *param1);
  StatsUpgradeRequestMessage();

  bool useAdditionnal;
  uint statId;
  uint boostPoint;
};

#endif // STATSUPGRADEREQUESTMESSAGE_H