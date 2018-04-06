#ifndef DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H
#define DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderAvailableDungeonsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderAvailableDungeonsMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(Reader *param1);
  DungeonPartyFinderAvailableDungeonsMessage();

  QList<uint> dungeonIds;
};

#endif // DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE_H