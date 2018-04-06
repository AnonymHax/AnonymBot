#ifndef ACQUAINTANCESERVERLISTMESSAGE_H
#define ACQUAINTANCESERVERLISTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AcquaintanceServerListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AcquaintanceServerListMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AcquaintanceServerListMessage(Reader *param1);
  AcquaintanceServerListMessage();

  QList<uint> servers;
};

#endif // ACQUAINTANCESERVERLISTMESSAGE_H