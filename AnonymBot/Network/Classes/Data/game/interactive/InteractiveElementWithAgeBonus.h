#ifndef INTERACTIVEELEMENTWITHAGEBONUS_H
#define INTERACTIVEELEMENTWITHAGEBONUS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"
#include "Network/Classes/Data/game/interactive/InteractiveElement.h"

class InteractiveElementWithAgeBonus : public InteractiveElement
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_InteractiveElementWithAgeBonus(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_InteractiveElementWithAgeBonus(Reader *param1);
  InteractiveElementWithAgeBonus();
  bool operator==(const InteractiveElementWithAgeBonus &compared);

  int ageBonus;
};

#endif // INTERACTIVEELEMENTWITHAGEBONUS_H