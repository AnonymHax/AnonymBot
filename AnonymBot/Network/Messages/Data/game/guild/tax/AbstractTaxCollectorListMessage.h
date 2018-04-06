#ifndef ABSTRACTTAXCOLLECTORLISTMESSAGE_H
#define ABSTRACTTAXCOLLECTORLISTMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Classes/ClassManager.h"

class AbstractTaxCollectorListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractTaxCollectorListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractTaxCollectorListMessage(Reader *param1);
  AbstractTaxCollectorListMessage();

  QList<QSharedPointer<TaxCollectorInformations>> informations;
};

#endif // ABSTRACTTAXCOLLECTORLISTMESSAGE_H