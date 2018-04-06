#ifndef SYMBIOTICOBJECTERRORMESSAGE_H
#define SYMBIOTICOBJECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObjectErrorMessage.h"
#include "Network/Messages/Data/game/inventory/items/ObjectErrorMessage.h"

class SymbioticObjectErrorMessage : public ObjectErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SymbioticObjectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SymbioticObjectErrorMessage(Reader *param1);
  SymbioticObjectErrorMessage();

  int errorCode;
};

#endif // SYMBIOTICOBJECTERRORMESSAGE_H