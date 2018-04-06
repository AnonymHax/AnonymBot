#ifndef GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H
#define GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H

#include "Network/Messages/AbstractMessage.h"

class GameRolePlayArenaRegistrationStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *param1);
  void serializeAs_GameRolePlayArenaRegistrationStatusMessage(Writer *param1);
  virtual void deserialize(Reader *param1);
  void deserializeAs_GameRolePlayArenaRegistrationStatusMessage(Reader *param1);
  GameRolePlayArenaRegistrationStatusMessage();

  bool registered;
  uint step;
  uint battleMode;
};

#endif // GAMEROLEPLAYARENAREGISTRATIONSTATUSMESSAGE_H