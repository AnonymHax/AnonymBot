#ifndef QUESTSTARTEDMESSAGE_H
#define QUESTSTARTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStartedMessage(Reader *param1);
  QuestStartedMessage();

  uint questId;
};

#endif // QUESTSTARTEDMESSAGE_H