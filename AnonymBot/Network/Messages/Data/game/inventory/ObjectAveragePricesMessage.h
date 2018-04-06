#ifndef OBJECTAVERAGEPRICESMESSAGE_H
#define OBJECTAVERAGEPRICESMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectAveragePricesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectAveragePricesMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectAveragePricesMessage(Reader *param1);
  ObjectAveragePricesMessage();

  QList<uint> ids;
  QList<uint> avgPrices;
};

#endif // OBJECTAVERAGEPRICESMESSAGE_H