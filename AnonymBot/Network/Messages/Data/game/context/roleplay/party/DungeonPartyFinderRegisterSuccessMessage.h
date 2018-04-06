#ifndef DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderRegisterSuccessMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderRegisterSuccessMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderRegisterSuccessMessage(Reader *param1);
  DungeonPartyFinderRegisterSuccessMessage();

  QList<uint> dungeonIds;
};

#endif // DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE_H