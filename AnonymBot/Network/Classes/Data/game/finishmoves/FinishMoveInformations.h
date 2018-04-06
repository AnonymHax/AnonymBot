#ifndef FINISHMOVEINFORMATIONS_H
#define FINISHMOVEINFORMATIONS_H

#include "Network/Classes/AbstractClass.h"

class FinishMoveInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_FinishMoveInformations(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_FinishMoveInformations(Reader *param1);
  FinishMoveInformations();
  bool operator==(const FinishMoveInformations &compared);

  uint finishMoveId;
  bool finishMoveState;
};

#endif // FINISHMOVEINFORMATIONS_H