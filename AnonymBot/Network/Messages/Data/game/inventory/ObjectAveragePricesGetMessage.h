#ifndef OBJECTAVERAGEPRICESGETMESSAGE_H
#define OBJECTAVERAGEPRICESGETMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectAveragePricesGetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectAveragePricesGetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectAveragePricesGetMessage(Reader *param1);
  ObjectAveragePricesGetMessage();
};

#endif // OBJECTAVERAGEPRICESGETMESSAGE_H