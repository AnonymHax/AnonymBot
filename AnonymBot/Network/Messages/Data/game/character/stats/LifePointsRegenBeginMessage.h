#ifndef LIFEPOINTSREGENBEGINMESSAGE_H
#define LIFEPOINTSREGENBEGINMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class LifePointsRegenBeginMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_LifePointsRegenBeginMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_LifePointsRegenBeginMessage(Reader *param1);
  LifePointsRegenBeginMessage();

  uint regenRate;
};

#endif // LIFEPOINTSREGENBEGINMESSAGE_H