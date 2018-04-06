#ifndef NUMERICWHOISMESSAGE_H
#define NUMERICWHOISMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class NumericWhoIsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_NumericWhoIsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_NumericWhoIsMessage(Reader *param1);
  NumericWhoIsMessage();

  double playerId;
  uint accountId;
};

#endif // NUMERICWHOISMESSAGE_H