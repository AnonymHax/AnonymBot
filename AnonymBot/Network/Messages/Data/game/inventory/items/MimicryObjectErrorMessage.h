#ifndef MIMICRYOBJECTERRORMESSAGE_H
#define MIMICRYOBJECTERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/inventory/items/SymbioticObjectErrorMessage.h"

class MimicryObjectErrorMessage : public SymbioticObjectErrorMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_MimicryObjectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_MimicryObjectErrorMessage(Reader *param1);
  MimicryObjectErrorMessage();

  bool preview;
};

#endif // MIMICRYOBJECTERRORMESSAGE_H