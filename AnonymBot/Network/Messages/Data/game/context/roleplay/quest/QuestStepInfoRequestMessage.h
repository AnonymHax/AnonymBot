#ifndef QUESTSTEPINFOREQUESTMESSAGE_H
#define QUESTSTEPINFOREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class QuestStepInfoRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStepInfoRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStepInfoRequestMessage(Reader *param1);
  QuestStepInfoRequestMessage();

  uint questId;
};

#endif // QUESTSTEPINFOREQUESTMESSAGE_H