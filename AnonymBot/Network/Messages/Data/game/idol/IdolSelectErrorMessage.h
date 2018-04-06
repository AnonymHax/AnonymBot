#ifndef IDOLSELECTERRORMESSAGE_H
#define IDOLSELECTERRORMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IdolSelectErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolSelectErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolSelectErrorMessage(Reader *param1);
  IdolSelectErrorMessage();

  uint reason;
  uint idolId;
  bool activate;
  bool party;
};

#endif // IDOLSELECTERRORMESSAGE_H