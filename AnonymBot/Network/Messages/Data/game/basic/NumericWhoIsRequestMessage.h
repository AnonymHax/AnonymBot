#ifndef NUMERICWHOISREQUESTMESSAGE_H
#define NUMERICWHOISREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NumericWhoIsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NumericWhoIsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NumericWhoIsRequestMessage(Reader *param1);
  NumericWhoIsRequestMessage();

  double playerId;
};

#endif // NUMERICWHOISREQUESTMESSAGE_H