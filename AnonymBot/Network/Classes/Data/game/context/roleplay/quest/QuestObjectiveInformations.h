#ifndef QUESTOBJECTIVEINFORMATIONS_H
#define QUESTOBJECTIVEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class QuestObjectiveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestObjectiveInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestObjectiveInformations(Reader *param1);
  QuestObjectiveInformations();
  bool operator==(const QuestObjectiveInformations &compared);

  uint objectiveId;
  bool objectiveStatus;
  QList<QString> dialogParams;
};

#endif // QUESTOBJECTIVEINFORMATIONS_H