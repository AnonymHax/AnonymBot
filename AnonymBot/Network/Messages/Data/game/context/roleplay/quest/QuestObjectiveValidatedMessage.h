#ifndef QUESTOBJECTIVEVALIDATEDMESSAGE_H
#define QUESTOBJECTIVEVALIDATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestObjectiveValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestObjectiveValidatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestObjectiveValidatedMessage(Reader *param1);
  QuestObjectiveValidatedMessage();

  uint questId;
  uint objectiveId;
};

#endif // QUESTOBJECTIVEVALIDATEDMESSAGE_H