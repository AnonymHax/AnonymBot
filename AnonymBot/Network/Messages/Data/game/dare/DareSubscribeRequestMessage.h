#ifndef DARESUBSCRIBEREQUESTMESSAGE_H
#define DARESUBSCRIBEREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DareSubscribeRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DareSubscribeRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DareSubscribeRequestMessage(Reader *param1);
  DareSubscribeRequestMessage();

  double dareId;
  bool subscribe;
};

#endif // DARESUBSCRIBEREQUESTMESSAGE_H