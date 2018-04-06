#ifndef MIMICRYOBJECTASSOCIATEDMESSAGE_H
#define MIMICRYOBJECTASSOCIATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

class MimicryObjectAssociatedMessage : public SymbioticObjectAssociatedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MimicryObjectAssociatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MimicryObjectAssociatedMessage(Reader *param1);
  MimicryObjectAssociatedMessage();
};

#endif // MIMICRYOBJECTASSOCIATEDMESSAGE_H