#ifndef HUMANOPTION_H
#define HUMANOPTION_H

#include "Network/Classes/AbstractClass.h"

class HumanOption : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HumanOption(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HumanOption(Reader *param1);
  HumanOption();
  bool operator==(const HumanOption &compared);
};

#endif // HUMANOPTION_H