#ifndef KROSMASTERINVENTORYERRORMESSAGE_H
#define KROSMASTERINVENTORYERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterInventoryErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterInventoryErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterInventoryErrorMessage(Reader *param1);
  KrosmasterInventoryErrorMessage();

  uint reason;
};

#endif // KROSMASTERINVENTORYERRORMESSAGE_H