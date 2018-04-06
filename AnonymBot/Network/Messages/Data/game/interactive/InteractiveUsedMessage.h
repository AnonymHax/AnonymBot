#ifndef INTERACTIVEUSEDMESSAGE_H
#define INTERACTIVEUSEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class InteractiveUsedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveUsedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveUsedMessage(Reader *param1);
  InteractiveUsedMessage();

  double entityId;
  uint elemId;
  uint skillId;
  uint duration;
  bool canMove;
};

#endif // INTERACTIVEUSEDMESSAGE_H