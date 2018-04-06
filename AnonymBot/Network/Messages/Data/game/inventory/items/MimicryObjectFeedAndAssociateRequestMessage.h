#ifndef MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H
#define MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/SymbioticObjectAssociateRequestMessage.h"

class MimicryObjectFeedAndAssociateRequestMessage : public SymbioticObjectAssociateRequestMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MimicryObjectFeedAndAssociateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MimicryObjectFeedAndAssociateRequestMessage(Reader *param1);
  MimicryObjectFeedAndAssociateRequestMessage();

  uint foodUID;
  uint foodPos;
  bool preview;
};

#endif // MIMICRYOBJECTFEEDANDASSOCIATEREQUESTMESSAGE_H