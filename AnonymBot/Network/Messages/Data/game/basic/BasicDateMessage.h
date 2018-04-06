#ifndef BASICDATEMESSAGE_H
#define BASICDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicDateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicDateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicDateMessage(Reader *param1);
  BasicDateMessage();

  uint day;
  uint month;
  uint year;
};

#endif // BASICDATEMESSAGE_H