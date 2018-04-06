#ifndef OBJECTEFFECT_H
#define OBJECTEFFECT_H

#include "Network/Classes/AbstractClass.h"

class ObjectEffect : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectEffect(Reader *param1);
  ObjectEffect();
  bool operator==(const ObjectEffect &compared);

  uint actionId;
};

#endif // OBJECTEFFECT_H