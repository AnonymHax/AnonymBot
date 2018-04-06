#ifndef BASICWHOISREQUESTMESSAGE_H
#define BASICWHOISREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicWhoIsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicWhoIsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicWhoIsRequestMessage(Reader *param1);
  BasicWhoIsRequestMessage();

  bool verbose;
  QString search;
};

#endif // BASICWHOISREQUESTMESSAGE_H