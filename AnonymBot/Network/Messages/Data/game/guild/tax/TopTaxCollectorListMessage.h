#ifndef TOPTAXCOLLECTORLISTMESSAGE_H
#define TOPTAXCOLLECTORLISTMESSAGE_H

#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/guild/tax/AbstractTaxCollectorListMessage.h"
#include "Network/Classes/Data/game/guild/tax/TaxCollectorInformations.h"

class TopTaxCollectorListMessage : public AbstractTaxCollectorListMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TopTaxCollectorListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TopTaxCollectorListMessage(Reader *param1);
  TopTaxCollectorListMessage();

  bool isDungeon;
};

#endif // TOPTAXCOLLECTORLISTMESSAGE_H