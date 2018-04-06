#ifndef ACQUAINTANCESEARCHMESSAGE_H
#define ACQUAINTANCESEARCHMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AcquaintanceSearchMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AcquaintanceSearchMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AcquaintanceSearchMessage(Reader *param1);
  AcquaintanceSearchMessage();

  QString nickname;
};

#endif // ACQUAINTANCESEARCHMESSAGE_H