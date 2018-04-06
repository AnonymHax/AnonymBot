#ifndef SLAVESWITCHCONTEXTMESSAGE_H
#define SLAVESWITCHCONTEXTMESSAGE_H

#include "Network/Classes/Data/game/data/items/SpellItem.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"
#include "Network/Messages/AbstractMessage.h"
#include "Network/Classes/Data/game/data/items/SpellItem.h"
#include "Network/Classes/Data/game/character/characteristic/CharacterCharacteristicsInformations.h"
#include "Network/Classes/Data/game/shortcut/Shortcut.h"
#include "Network/Classes/ClassManager.h"

class SlaveSwitchContextMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_SlaveSwitchContextMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_SlaveSwitchContextMessage(Reader *param1);
  SlaveSwitchContextMessage();

  double masterId;
  double slaveId;
  QList<SpellItem> slaveSpells;
  CharacterCharacteristicsInformations slaveStats;
  QList<QSharedPointer<Shortcut>> shortcuts;
};

#endif // SLAVESWITCHCONTEXTMESSAGE_H