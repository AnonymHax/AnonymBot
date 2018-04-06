#ifndef TAXCOLLECTORMOVEMENTMESSAGE_H
#define TAXCOLLECTORMOVEMENTMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorBasicInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorBasicInformations.h"

class TaxCollectorMovementMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorMovementMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorMovementMessage(Reader *param1);
  TaxCollectorMovementMessage();

  uint movementType;
  TaxCollectorBasicInformations basicInfos;
  double playerId;
  QString playerName;
};

#endif // TAXCOLLECTORMOVEMENTMESSAGE_H