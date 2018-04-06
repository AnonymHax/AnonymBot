#ifndef QUESTSTEPVALIDATEDMESSAGE_H
#define QUESTSTEPVALIDATEDMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestStepValidatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStepValidatedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStepValidatedMessage(Reader *param1);
  QuestStepValidatedMessage();

  uint questId;
  uint stepId;
};

#endif // QUESTSTEPVALIDATEDMESSAGE_H