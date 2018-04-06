#ifndef IDOLPARTYLOSTMESSAGE_H
#define IDOLPARTYLOSTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class IdolPartyLostMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_IdolPartyLostMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_IdolPartyLostMessage(Reader *param1);
  IdolPartyLostMessage();

  uint idolId;
};

#endif // IDOLPARTYLOSTMESSAGE_H