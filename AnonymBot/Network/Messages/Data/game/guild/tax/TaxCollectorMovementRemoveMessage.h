#ifndef TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H
#define TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TaxCollectorMovementRemoveMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorMovementRemoveMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorMovementRemoveMessage(Reader *param1);
  TaxCollectorMovementRemoveMessage();

  int collectorId;
};

#endif // TAXCOLLECTORMOVEMENTREMOVEMESSAGE_H