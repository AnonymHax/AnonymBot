#ifndef QUESTSTEPSTARTEDMESSAGE_H
#define QUESTSTEPSTARTEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestStepStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStepStartedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStepStartedMessage(Reader *param1);
  QuestStepStartedMessage();

  uint questId;
  uint stepId;
};

#endif // QUESTSTEPSTARTEDMESSAGE_H