#ifndef ABSTRACTGAMEACTIONMESSAGE_H
#define ABSTRACTGAMEACTIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class AbstractGameActionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractGameActionMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractGameActionMessage(Reader *param1);
  AbstractGameActionMessage();

  uint actionId;
  double sourceId;
};

#endif // ABSTRACTGAMEACTIONMESSAGE_H