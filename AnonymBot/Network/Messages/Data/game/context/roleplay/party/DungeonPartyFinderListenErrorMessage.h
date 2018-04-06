#ifndef DUNGEONPARTYFINDERLISTENERRORMESSAGE_H
#define DUNGEONPARTYFINDERLISTENERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderListenErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderListenErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderListenErrorMessage(Reader *param1);
  DungeonPartyFinderListenErrorMessage();

  uint dungeonId;
};

#endif // DUNGEONPARTYFINDERLISTENERRORMESSAGE_H