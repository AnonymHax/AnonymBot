#ifndef QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H
#define QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"
#include "Network/Classes/Data/game/context/roleplay/quest/QuestObjectiveInformations.h"

class QuestObjectiveInformationsWithCompletion : public QuestObjectiveInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestObjectiveInformationsWithCompletion(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestObjectiveInformationsWithCompletion(Reader *param1);
  QuestObjectiveInformationsWithCompletion();
  bool operator==(const QuestObjectiveInformationsWithCompletion &compared);

  uint curCompletion;
  uint maxCompletion;
};

#endif // QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION_H