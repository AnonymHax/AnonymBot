#ifndef SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H
#define SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class SymbioticObjectAssociateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SymbioticObjectAssociateRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SymbioticObjectAssociateRequestMessage(Reader *param1);
  SymbioticObjectAssociateRequestMessage();

  uint symbioteUID;
  uint symbiotePos;
  uint hostUID;
  uint hostPos;
};

#endif // SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE_H