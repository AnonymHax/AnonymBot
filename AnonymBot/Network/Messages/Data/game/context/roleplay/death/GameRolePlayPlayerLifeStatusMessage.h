#ifndef GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H
#define GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayPlayerLifeStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayPlayerLifeStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayPlayerLifeStatusMessage(Reader *param1);
  GameRolePlayPlayerLifeStatusMessage();

  uint state;
  uint phenixMapId;
};

#endif // GAMEROLEPLAYPLAYERLIFESTATUSMESSAGE_H