#ifndef INTERACTIVEUSEENDEDMESSAGE_H
#define INTERACTIVEUSEENDEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InteractiveUseEndedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveUseEndedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveUseEndedMessage(Reader *param1);
  InteractiveUseEndedMessage();

  uint elemId;
  uint skillId;
};

#endif // INTERACTIVEUSEENDEDMESSAGE_H