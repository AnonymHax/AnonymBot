#ifndef SYMBIOTICOBJECTASSOCIATEDMESSAGE_H
#define SYMBIOTICOBJECTASSOCIATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SymbioticObjectAssociatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SymbioticObjectAssociatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SymbioticObjectAssociatedMessage(Reader *param1);
  SymbioticObjectAssociatedMessage();

  uint hostUID;
};

#endif // SYMBIOTICOBJECTASSOCIATEDMESSAGE_H