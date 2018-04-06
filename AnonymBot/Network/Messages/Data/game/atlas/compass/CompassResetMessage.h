#ifndef COMPASSRESETMESSAGE_H
#define COMPASSRESETMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class CompassResetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_CompassResetMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_CompassResetMessage(Reader *param1);
  CompassResetMessage();

  uint type;
};

#endif // COMPASSRESETMESSAGE_H