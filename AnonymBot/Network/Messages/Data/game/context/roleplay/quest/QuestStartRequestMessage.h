#ifndef QUESTSTARTREQUESTMESSAGE_H
#define QUESTSTARTREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestStartRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStartRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStartRequestMessage(Reader *param1);
  QuestStartRequestMessage();

  uint questId;
};

#endif // QUESTSTARTREQUESTMESSAGE_H