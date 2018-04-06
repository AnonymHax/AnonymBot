#ifndef KAMASUPDATEMESSAGE_H
#define KAMASUPDATEMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class KamasUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_KamasUpdateMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_KamasUpdateMessage(Reader *param1);
  KamasUpdateMessage();

  int kamasTotal;
};

#endif // KAMASUPDATEMESSAGE_H