#ifndef OBJECTITEMINROLEPLAY_H
#define OBJECTITEMINROLEPLAY_H

#include "Network/Classes/AbstractClass.h"

class ObjectItemInRolePlay : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ObjectItemInRolePlay(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ObjectItemInRolePlay(Reader *param1);
  ObjectItemInRolePlay();
  bool operator==(const ObjectItemInRolePlay &compared);

  uint cellId;
  uint objectGID;
};

#endif // OBJECTITEMINROLEPLAY_H