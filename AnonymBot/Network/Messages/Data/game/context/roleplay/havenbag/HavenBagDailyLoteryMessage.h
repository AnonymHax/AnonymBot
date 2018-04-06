#ifndef HAVENBAGDAILYLOTERYMESSAGE_H
#define HAVENBAGDAILYLOTERYMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class HavenBagDailyLoteryMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_HavenBagDailyLoteryMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_HavenBagDailyLoteryMessage(Reader *param1);
  HavenBagDailyLoteryMessage();

  uint returnType;
  QString tokenId;
};

#endif // HAVENBAGDAILYLOTERYMESSAGE_H