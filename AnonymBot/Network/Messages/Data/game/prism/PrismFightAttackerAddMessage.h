#ifndef PRISMFIGHTATTACKERADDMESSAGE_H
#define PRISMFIGHTATTACKERADDMESSAGE_H

#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "Network/Classes/ClassManager.h"

class PrismFightAttackerAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_PrismFightAttackerAddMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_PrismFightAttackerAddMessage(Reader *param1);
  PrismFightAttackerAddMessage();

  uint subAreaId;
  uint fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> attacker;
};

#endif // PRISMFIGHTATTACKERADDMESSAGE_H