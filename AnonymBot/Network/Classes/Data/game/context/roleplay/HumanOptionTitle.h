#ifndef HUMANOPTIONTITLE_H
#define HUMANOPTIONTITLE_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"
#include "Network/Classes/Data/game/context/roleplay/HumanOption.h"

class HumanOptionTitle : public HumanOption
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOptionTitle(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOptionTitle(Reader *param1);
  HumanOptionTitle();
  bool operator==(const HumanOptionTitle &compared);

  uint titleId;
  QString titleParam;
};

#endif // HUMANOPTIONTITLE_H