#ifndef WRAPPEROBJECTASSOCIATEDMESSAGE_H
#define WRAPPEROBJECTASSOCIATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/SymbioticObjectAssociatedMessage.h"

class WrapperObjectAssociatedMessage : public SymbioticObjectAssociatedMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_WrapperObjectAssociatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_WrapperObjectAssociatedMessage(Reader *param1);
  WrapperObjectAssociatedMessage();
};

#endif // WRAPPEROBJECTASSOCIATEDMESSAGE_H