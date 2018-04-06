#ifndef BASICTIMEMESSAGE_H
#define BASICTIMEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class BasicTimeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_BasicTimeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_BasicTimeMessage(Reader *param1);
  BasicTimeMessage();

  double timestamp;
  int timezoneOffset;
};

#endif // BASICTIMEMESSAGE_H