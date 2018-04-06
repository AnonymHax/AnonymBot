#ifndef IDOLSELECTREQUESTMESSAGE_H
#define IDOLSELECTREQUESTMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IdolSelectRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolSelectRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolSelectRequestMessage(Reader *param1);
  IdolSelectRequestMessage();

  uint idolId;
  bool activate;
  bool party;
};

#endif // IDOLSELECTREQUESTMESSAGE_H