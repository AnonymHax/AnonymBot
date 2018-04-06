#ifndef DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderAvailableDungeonsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderAvailableDungeonsRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderAvailableDungeonsRequestMessage(Reader *param1);
  DungeonPartyFinderAvailableDungeonsRequestMessage();
};

#endif // DUNGEONPARTYFINDERAVAILABLEDUNGEONSREQUESTMESSAGE_H