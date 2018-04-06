#ifndef QUESTACTIVEINFORMATIONS_H
#define QUESTACTIVEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class QuestActiveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_QuestActiveInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_QuestActiveInformations(Reader *param1);
  QuestActiveInformations();
  bool operator==(const QuestActiveInformations &compared);

  uint questId;
};

#endif // QUESTACTIVEINFORMATIONS_H