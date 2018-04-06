#ifndef TAXCOLLECTORMOVEMENTADDMESSAGE_H
#define TAXCOLLECTORMOVEMENTADDMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Classes/ClassManager.h"

class TaxCollectorMovementAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorMovementAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorMovementAddMessage(Reader *param1);
  TaxCollectorMovementAddMessage();

  QSharedPointer<TaxCollectorInformations> informations;
};

#endif // TAXCOLLECTORMOVEMENTADDMESSAGE_H