#ifndef ACTORORIENTATION_H
#define ACTORORIENTATION_H

#include "Network/Classes/AbstractClass.h"

class ActorOrientation : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ActorOrientation(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ActorOrientation(Reader *param1);
  ActorOrientation();
  bool operator==(const ActorOrientation &compared);

  double id;
  uint direction;
};

#endif // ACTORORIENTATION_H