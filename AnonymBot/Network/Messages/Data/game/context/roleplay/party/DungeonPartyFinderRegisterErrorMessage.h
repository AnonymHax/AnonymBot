#ifndef DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H
#define DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class DungeonPartyFinderRegisterErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_DungeonPartyFinderRegisterErrorMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_DungeonPartyFinderRegisterErrorMessage(Reader *param1);
  DungeonPartyFinderRegisterErrorMessage();
};

#endif // DUNGEONPARTYFINDERREGISTERERRORMESSAGE_H