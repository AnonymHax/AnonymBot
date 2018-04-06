#ifndef ABSTRACTCHARACTERINFORMATION_H
#define ABSTRACTCHARACTERINFORMATION_H

#include "Network/Classes/AbstractClass.h"

class AbstractCharacterInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractCharacterInformation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractCharacterInformation(Reader *param1);
  AbstractCharacterInformation();
  bool operator==(const AbstractCharacterInformation &compared);

  double id;
};

#endif // ABSTRACTCHARACTERINFORMATION_H