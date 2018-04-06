#ifndef BASICWHOAMIREQUESTMESSAGE_H
#define BASICWHOAMIREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicWhoAmIRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicWhoAmIRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicWhoAmIRequestMessage(Reader *param1);
  BasicWhoAmIRequestMessage();

  bool verbose;
};

#endif // BASICWHOAMIREQUESTMESSAGE_H