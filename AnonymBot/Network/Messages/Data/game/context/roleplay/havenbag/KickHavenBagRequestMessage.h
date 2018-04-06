#ifndef KICKHAVENBAGREQUESTMESSAGE_H
#define KICKHAVENBAGREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KickHavenBagRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KickHavenBagRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KickHavenBagRequestMessage(Reader *param1);
  KickHavenBagRequestMessage();

  double guestId;
};

#endif // KICKHAVENBAGREQUESTMESSAGE_H