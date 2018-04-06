#ifndef GUESTMODEMESSAGE_H
#define GUESTMODEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GuestModeMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GuestModeMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GuestModeMessage(Reader *param1);
  GuestModeMessage();

  bool active;
};

#endif // GUESTMODEMESSAGE_H