#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementSkill.h"
#include "Network/Classes/Data/game/interactive/InteractiveElementSkill.h"
#include "Network/Classes/ClassManager.h"

class InteractiveElement : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveElement(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveElement(Reader *param1);
  InteractiveElement();
  bool operator==(const InteractiveElement &compared);

  uint elementId;
  int elementTypeId;
  QList<QSharedPointer<InteractiveElementSkill>> enabledSkills;
  QList<QSharedPointer<InteractiveElementSkill>> disabledSkills;
  bool onCurrentMap;
};

#endif // INTERACTIVEELEMENT_H