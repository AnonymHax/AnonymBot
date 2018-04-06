#ifndef ACTORALIGNMENTINFORMATIONS_H
#define ACTORALIGNMENTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class ActorAlignmentInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ActorAlignmentInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ActorAlignmentInformations(Reader *param1);
  ActorAlignmentInformations();
  bool operator==(const ActorAlignmentInformations &compared);

  int alignmentSide;
  uint alignmentValue;
  uint alignmentGrade;
  double characterPower;
};

#endif // ACTORALIGNMENTINFORMATIONS_H