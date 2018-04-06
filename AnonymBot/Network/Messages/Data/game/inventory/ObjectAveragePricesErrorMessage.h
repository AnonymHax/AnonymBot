#ifndef OBJECTAVERAGEPRICESERRORMESSAGE_H
#define OBJECTAVERAGEPRICESERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ObjectAveragePricesErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectAveragePricesErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectAveragePricesErrorMessage(Reader *param1);
  ObjectAveragePricesErrorMessage();
};

#endif // OBJECTAVERAGEPRICESERRORMESSAGE_H