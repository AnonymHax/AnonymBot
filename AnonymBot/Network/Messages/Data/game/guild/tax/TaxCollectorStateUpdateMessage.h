#ifndef TAXCOLLECTORSTATEUPDATEMESSAGE_H
#define TAXCOLLECTORSTATEUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class TaxCollectorStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TaxCollectorStateUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TaxCollectorStateUpdateMessage(Reader *param1);
  TaxCollectorStateUpdateMessage();

  int uniqueId;
  int state;
};

#endif // TAXCOLLECTORSTATEUPDATEMESSAGE_H