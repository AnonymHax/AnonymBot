#ifndef PRISMFIGHTADDEDMESSAGE_H
#define PRISMFIGHTADDEDMESSAGE_H

#include "Network/Classes/Data/game/prism/PrismFightersInformation.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/prism/PrismFightersInformation.h"

class PrismFightAddedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightAddedMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightAddedMessage(Reader *param1);
  PrismFightAddedMessage();

  QSharedPointer<PrismFightersInformation> fight;
};

#endif // PRISMFIGHTADDEDMESSAGE_H