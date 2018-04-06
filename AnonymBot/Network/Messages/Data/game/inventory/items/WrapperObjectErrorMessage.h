#ifndef WRAPPEROBJECTERRORMESSAGE_H
#define WRAPPEROBJECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/SymbioticObjectErrorMessage.h"

class WrapperObjectErrorMessage : public SymbioticObjectErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_WrapperObjectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_WrapperObjectErrorMessage(Reader *param1);
  WrapperObjectErrorMessage();
};

#endif // WRAPPEROBJECTERRORMESSAGE_H