#ifndef QUESTSTEPINFOMESSAGE_H
#define QUESTSTEPINFOMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/ClassManager.h"

class QuestStepInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestStepInfoMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestStepInfoMessage(Reader *param1);
  QuestStepInfoMessage();

  QSharedPointer<QuestActiveInformations> infos;
};

#endif // QUESTSTEPINFOMESSAGE_H