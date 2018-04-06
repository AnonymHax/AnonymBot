#ifndef ABSTRACTFIGHTDISPELLABLEEFFECT_H
#define ABSTRACTFIGHTDISPELLABLEEFFECT_H

#include "Network/Classes/AbstractClass.h"

class AbstractFightDispellableEffect : public AbstractClass
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_AbstractFightDispellableEffect(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_AbstractFightDispellableEffect(Reader *param1);
  AbstractFightDispellableEffect();
  bool operator==(const AbstractFightDispellableEffect &compared);

  uint uid;
  double targetId;
  int turnDuration;
  uint dispelable;
  uint spellId;
  uint effectId;
  uint parentBoostUid;
};

#endif // ABSTRACTFIGHTDISPELLABLEEFFECT_H