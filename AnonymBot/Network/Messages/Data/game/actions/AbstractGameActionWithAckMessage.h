#ifndef ABSTRACTGAMEACTIONWITHACKMESSAGE_H
#define ABSTRACTGAMEACTIONWITHACKMESSAGE_H

#include "Network/Messages/AbstractMessage.h"
#include "Network/Messages/Data/game/actions/AbstractGameActionMessage.h"

class AbstractGameActionWithAckMessage : public AbstractGameActionMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractGameActionWithAckMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractGameActionWithAckMessage(Reader *param1);
  AbstractGameActionWithAckMessage();

  int waitAckId;
};

#endif // ABSTRACTGAMEACTIONWITHACKMESSAGE_H