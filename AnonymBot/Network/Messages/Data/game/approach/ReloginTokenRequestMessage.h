#ifndef RELOGINTOKENREQUESTMESSAGE_H
#define RELOGINTOKENREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class ReloginTokenRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ReloginTokenRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ReloginTokenRequestMessage(Reader *param1);
  ReloginTokenRequestMessage();
};

#endif // RELOGINTOKENREQUESTMESSAGE_H