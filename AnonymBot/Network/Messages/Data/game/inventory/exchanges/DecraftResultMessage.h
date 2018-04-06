#ifndef DECRAFTRESULTMESSAGE_H
#define DECRAFTRESULTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/job/DecraftedItemStackInfo.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/job/DecraftedItemStackInfo.h"

class DecraftResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DecraftResultMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DecraftResultMessage(Reader *param1);
  DecraftResultMessage();

  QList<DecraftedItemStackInfo> results;
};

#endif // DECRAFTRESULTMESSAGE_H