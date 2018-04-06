#ifndef QUESTOBJECTIVEVALIDATIONMESSAGE_H
#define QUESTOBJECTIVEVALIDATIONMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestObjectiveValidationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestObjectiveValidationMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestObjectiveValidationMessage(Reader *param1);
  QuestObjectiveValidationMessage();

  uint questId;
  uint objectiveId;
};

#endif // QUESTOBJECTIVEVALIDATIONMESSAGE_H