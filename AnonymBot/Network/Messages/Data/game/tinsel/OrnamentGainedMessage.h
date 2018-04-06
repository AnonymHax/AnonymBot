#ifndef ORNAMENTGAINEDMESSAGE_H
#define ORNAMENTGAINEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class OrnamentGainedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_OrnamentGainedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_OrnamentGainedMessage(Reader *param1);
  OrnamentGainedMessage();

  uint ornamentId;
};

#endif // ORNAMENTGAINEDMESSAGE_H