#ifndef ACTOREXTENDEDALIGNMENTINFORMATIONS_H
#define ACTOREXTENDEDALIGNMENTINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"
#include "Network/Classes/Data/game/character/alignment/ActorAlignmentInformations.h"

class ActorExtendedAlignmentInformations : public ActorAlignmentInformations
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_ActorExtendedAlignmentInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_ActorExtendedAlignmentInformations(Reader *param1);
  ActorExtendedAlignmentInformations();
  bool operator==(const ActorExtendedAlignmentInformations &compared);

  uint honor;
  uint honorGradeFloor;
  uint honorNextGradeFloor;
  uint aggressable;
};

#endif // ACTOREXTENDEDALIGNMENTINFORMATIONS_H