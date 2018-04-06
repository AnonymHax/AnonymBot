#ifndef PRISMSINFOVALIDMESSAGE_H
#define PRISMSINFOVALIDMESSAGE_H

#include "Network/Classes/Data/game/prism/PrismFightersInformation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/prism/PrismFightersInformation.h"

class PrismsInfoValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismsInfoValidMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismsInfoValidMessage(Reader *param1);
  PrismsInfoValidMessage();

  QList<QSharedPointer<PrismFightersInformation>> fights;
};

#endif // PRISMSINFOVALIDMESSAGE_H