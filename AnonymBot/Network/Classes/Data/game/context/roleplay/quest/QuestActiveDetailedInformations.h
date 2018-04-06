#ifndef QUESTACTIVEDETAILEDINFORMATIONS_H
#define QUESTACTIVEDETAILEDINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestActiveInformations.h"
#include "Network/Classes/ClassManager.h"

class QuestActiveDetailedInformations : public QuestActiveInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestActiveDetailedInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestActiveDetailedInformations(Reader *param1);
  QuestActiveDetailedInformations();
  bool operator==(const QuestActiveDetailedInformations &compared);

  uint stepId;
  QList<QSharedPointer<QuestObjectiveInformations>> objectives;
};

#endif // QUESTACTIVEDETAILEDINFORMATIONS_H