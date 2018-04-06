#ifndef UPDATELIFEPOINTSMESSAGE_H
#define UPDATELIFEPOINTSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class UpdateLifePointsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_UpdateLifePointsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_UpdateLifePointsMessage(Reader *param1);
  UpdateLifePointsMessage();

  uint lifePoints;
  uint maxLifePoints;
};

#endif // UPDATELIFEPOINTSMESSAGE_H