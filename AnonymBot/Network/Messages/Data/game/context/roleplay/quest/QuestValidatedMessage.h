#ifndef QUESTVALIDATEDMESSAGE_H
#define QUESTVALIDATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestValidatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestValidatedMessage(Reader *param1);
  QuestValidatedMessage();

  uint questId;
};

#endif // QUESTVALIDATEDMESSAGE_H