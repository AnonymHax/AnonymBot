#ifndef TREASUREHUNTLEGENDARYREQUESTMESSAGE_H
#define TREASUREHUNTLEGENDARYREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TreasureHuntLegendaryRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntLegendaryRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntLegendaryRequestMessage(Reader *param1);
  TreasureHuntLegendaryRequestMessage();

  uint legendaryId;
};

#endif // TREASUREHUNTLEGENDARYREQUESTMESSAGE_H