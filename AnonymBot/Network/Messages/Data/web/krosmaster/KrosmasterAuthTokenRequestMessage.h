#ifndef KROSMASTERAUTHTOKENREQUESTMESSAGE_H
#define KROSMASTERAUTHTOKENREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KrosmasterAuthTokenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KrosmasterAuthTokenRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KrosmasterAuthTokenRequestMessage(Reader *param1);
  KrosmasterAuthTokenRequestMessage();
};

#endif // KROSMASTERAUTHTOKENREQUESTMESSAGE_H