#ifndef ACQUAINTANCESEARCHERRORMESSAGE_H
#define ACQUAINTANCESEARCHERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AcquaintanceSearchErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AcquaintanceSearchErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AcquaintanceSearchErrorMessage(Reader *param1);
  AcquaintanceSearchErrorMessage();

  uint reason;
};

#endif // ACQUAINTANCESEARCHERRORMESSAGE_H