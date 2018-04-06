#ifndef TREASUREHUNTMESSAGE_H
#define TREASUREHUNTMESSAGE_H

#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntFlag.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntStep.h"
#include "Network/Classes/Data/game/context/roleplay/treasureHunt/TreasureHuntFlag.h"
#include "Network/Classes/ClassManager.h"

class TreasureHuntMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_TreasureHuntMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_TreasureHuntMessage(Reader *param1);
  TreasureHuntMessage();

  uint questType;
  int startMapId;
  QList<QSharedPointer<TreasureHuntStep>> knownStepsList;
  uint totalStepCount;
  uint checkPointCurrent;
  uint checkPointTotal;
  int availableRetryCount;
  QList<TreasureHuntFlag> flags;
};

#endif // TREASUREHUNTMESSAGE_H