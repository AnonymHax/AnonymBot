#ifndef IDOLSELECTEDMESSAGE_H
#define IDOLSELECTEDMESSAGE_H

#include "System/Tools/IO/BooleanByteWrapper.h"
#include "Network/Messages/AbstractMessage.h"
#include "System/Tools/IO/BooleanByteWrapper.h"

class IdolSelectedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolSelectedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolSelectedMessage(Reader *param1);
  IdolSelectedMessage();

  uint idolId;
  bool activate;
  bool party;
};

#endif // IDOLSELECTEDMESSAGE_H