#ifndef DARECANCELEDMESSAGE_H
#define DARECANCELEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareCanceledMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCanceledMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCanceledMessage(Reader *param1);
  DareCanceledMessage();

  double dareId;
};

#endif // DARECANCELEDMESSAGE_H