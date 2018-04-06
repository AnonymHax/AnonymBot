#ifndef PRISMFIGHTDEFENDERADDMESSAGE_H
#define PRISMFIGHTDEFENDERADDMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"

class PrismFightDefenderAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightDefenderAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightDefenderAddMessage(Reader *param1);
  PrismFightDefenderAddMessage();

  uint subAreaId;
  uint fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> defender;
};

#endif // PRISMFIGHTDEFENDERADDMESSAGE_H