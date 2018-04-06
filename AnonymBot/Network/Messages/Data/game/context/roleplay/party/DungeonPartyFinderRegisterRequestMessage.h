#ifndef DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderRegisterRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderRegisterRequestMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderRegisterRequestMessage(Reader *param1);
  DungeonPartyFinderRegisterRequestMessage();

  QList<uint> dungeonIds;
};

#endif // DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE_H