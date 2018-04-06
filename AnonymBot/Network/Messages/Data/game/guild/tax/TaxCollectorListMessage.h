#ifndef TAXCOLLECTORLISTMESSAGE_H
#define TAXCOLLECTORLISTMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorFightersInformation.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/guild/tax/AbstractTaxCollectorListMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorFightersInformation.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"

class TaxCollectorListMessage : public AbstractTaxCollectorListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorListMessage(Reader *param1);
  TaxCollectorListMessage();

  uint nbcollectorMax;
  QList<QSharedPointer<TaxCollectorFightersInformation>> fightersInformations;
};

#endif // TAXCOLLECTORLISTMESSAGE_H