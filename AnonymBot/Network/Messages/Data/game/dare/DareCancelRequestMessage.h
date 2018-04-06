#ifndef DARECANCELREQUESTMESSAGE_H
#define DARECANCELREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareCancelRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareCancelRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareCancelRequestMessage(Reader *param1);
  DareCancelRequestMessage();

  double dareId;
};

#endif // DARECANCELREQUESTMESSAGE_H