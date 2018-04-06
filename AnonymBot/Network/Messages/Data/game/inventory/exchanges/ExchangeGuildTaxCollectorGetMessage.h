#ifndef EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H
#define EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H

#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantity.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/ObjectItemGenericQuantity.h"

class ExchangeGuildTaxCollectorGetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ExchangeGuildTaxCollectorGetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ExchangeGuildTaxCollectorGetMessage(Reader *param1);
  ExchangeGuildTaxCollectorGetMessage();

  QString collectorName;
  int worldX;
  int worldY;
  int mapId;
  uint subAreaId;
  QString userName;
  double callerId;
  QString callerName;
  double experience;
  uint pods;
  QList<ObjectItemGenericQuantity> objectsInfos;
};

#endif // EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H