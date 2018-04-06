#ifndef TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H
#define TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorMovement.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorMovement.h"

class TaxCollectorMovementsOfflineMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorMovementsOfflineMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorMovementsOfflineMessage(Reader *param1);
  TaxCollectorMovementsOfflineMessage();

  QList<TaxCollectorMovement> movements;
};

#endif // TAXCOLLECTORMOVEMENTSOFFLINEMESSAGE_H